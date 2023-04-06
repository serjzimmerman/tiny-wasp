/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <tsimmerman.ss@phystech.edu> wrote this file.  As long
 * as you retain this notice you can do whatever you want with this stuff. If we
 * meet some day, and you think this stuff is worth it, you can buy me a beer in
 * return.
 * ----------------------------------------------------------------------------
 */

#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/atomic.h>

#include <util/delay.h>

#include "attiny24a/adc.hpp"
#include "attiny24a/cpu.hpp"
#include "attiny24a/porta.hpp"
#include "attiny24a/portb.hpp"

#include "attiny24a/exint.hpp"
#include "attiny24a/tc0.hpp"
#include "attiny24a/tc1.hpp"

#include <fpm/fixed.hpp>

#include <algorithm>
#include <array>
#include <bit>
#include <concepts>
#include <limits>
#include <ranges>
#include <utility>

namespace
{

using ufixed16_t = fpm::fixed<std::uint16_t, std::uint32_t, 8>;
using ufixed8_t = fpm::fixed<std::uint8_t, std::uint16_t, 5>;

using namespace avrcpp::attiny24a::mporta;
using namespace avrcpp::attiny24a::mportb;
using namespace avrcpp::attiny24a::madc;
using namespace avrcpp::attiny24a::mexint;
using namespace avrcpp::attiny24a::mtc1;
using namespace avrcpp::attiny24a::mtc0;
using namespace avrcpp::attiny24a::mcpu;

template <auto&> class eeprom_variable_wrapper
{ // Primary template
};

// This variable should be marked as EEMEM
template <typename T, T& variable_storage>
    requires ( sizeof( T ) == 1 )
class eeprom_variable_wrapper<variable_storage>
{
  private:
    uint8_t* eep_ptr() { return reinterpret_cast<uint8_t*>( &variable_storage ); }
    const uint8_t* eep_ptr() const { return reinterpret_cast<const uint8_t*>( &variable_storage ); }

  public:
    eeprom_variable_wrapper() = default;

    eeprom_variable_wrapper& operator=( const T& rhs )
    {
        eeprom_update_byte( eep_ptr(), *reinterpret_cast<const uint8_t*>( &rhs ) );
        return *this;
    }

    // clang-format off
    T get() const { auto res = eeprom_read_byte( eep_ptr() ); return *reinterpret_cast<T *>(&res); }
    operator T() const { return get(); }
    eeprom_variable_wrapper& operator|=( const T& rhs ) const& { *this = +*this | rhs; return *this; }
    eeprom_variable_wrapper& operator&=( const T& rhs ) const& { *this = +*this & rhs; return *this; }
    eeprom_variable_wrapper& operator^=( const T& rhs ) const& { *this = +*this ^ rhs; return *this; }
    eeprom_variable_wrapper& operator+=( const T& rhs ) const& { *this = +*this + rhs; return *this; }
    eeprom_variable_wrapper& operator-=( const T& rhs ) const& { *this = +*this - rhs; return *this; }
    // clang-format on
};

constexpr double cpu_frequency = F_CPU;

class led_indicator
{
  public:
    static void init()
    {
        disable();
        ddra |= ddra_fields::pa7;
    }

    static void enable() { porta &= ~porta_fields::pa7; }
    static void disable() { porta |= porta_fields::pa7; }
    static void toggle() { porta ^= porta_fields::pa7; }
};

struct tim0_flag;
struct tim1_flag;

namespace detail
{

template <typename flag> struct timer_prescaler_array_impl
{
};

template <> struct timer_prescaler_array_impl<tim0_flag>
{
    static constexpr auto value = std::array{
        tccr0b_fields::cs0_running_no_prescaling,
        tccr0b_fields::cs0_running_clk_8,
        tccr0b_fields::cs0_running_clk_64,
        tccr0b_fields::cs0_running_clk_64,
        tccr0b_fields::cs0_running_clk_256,
        tccr0b_fields::cs0_running_clk_1024 };
};

template <> struct timer_prescaler_array_impl<tim1_flag>
{
    static constexpr auto value = std::array{
        tccr1b_fields::cs1_running_no_prescaling,
        tccr1b_fields::cs1_running_clk_8,
        tccr1b_fields::cs1_running_clk_64,
        tccr1b_fields::cs1_running_clk_64,
        tccr1b_fields::cs1_running_clk_256,
        tccr1b_fields::cs1_running_clk_1024 };
};

template <typename flag> struct ocr_type_impl
{
};

template <> struct ocr_type_impl<tim0_flag>
{
    using type = uint8_t;
};

template <> struct ocr_type_impl<tim1_flag>
{
    using type = uint16_t;
};

} // namespace detail

template <typename flag> using ocr_type_t = typename detail::ocr_type_impl<flag>::type;

template <typename flag> struct clock_values
{
    ocr_type_t<flag> compare;
    uint8_t clock;
};

template <typename flag> constexpr auto timer_prescaler_array = detail::timer_prescaler_array_impl<flag>::value;

template <typename flag>
consteval clock_values<flag>
timer_prescalers( auto frequency_calc )
{
    using ocr_type = ocr_type_t<flag>;
    constexpr auto prescaler_coefficients = std::array{ 1.0, 8.0, 64.0, 256.0, 1024.0 };

    // clang-format off
    auto ocr_values = std::ranges::transform_view( prescaler_coefficients, 
        [ frequency_calc ]( auto&& presc ) {
            return frequency_calc( presc );
        }
    );
        
    auto indexed = std::ranges::transform_view( ocr_values, 
        [ i = 0 ]( auto&& val ) mutable {
            return std::pair{ val, i++ };
        } 
    ); // clang-format on

    auto compatible_values = std::ranges::filter_view( indexed, []( auto&& elem ) {
        auto&& [ ocr, index ] = elem;
        return ( ocr >= std::numeric_limits<ocr_type>::min() ) && ( ocr <= std::numeric_limits<ocr_type>::max() );
    } );

    if ( compatible_values.empty() )
    {
        throw "No suitable solution for prescaler found";
    }

    auto prescaler_array = timer_prescaler_array<flag>;
    auto [ found_coeff, index ] = *std::ranges::begin( compatible_values );
    return clock_values<flag>{ static_cast<ocr_type>( found_coeff ), prescaler_array.at( index ) };
}

class buzzer
{
  private:
    static consteval auto get_prescalers()
    {
        return timer_prescalers<tim1_flag>( [ target_frequency = 2700.0 ]( auto presc ) {
            return cpu_frequency / ( 2.0 * presc * target_frequency ) - 1;
        } );
    }

  public:
    static void init()
    {
        ocr1a = get_prescalers().compare;

        tccr1a = tccr1a_fields::wgm1_3 // Mode 7: Fast PWM
            | tccr1a_fields::com1a_1;  // Toggle on output compare

        tccr1b = tccr1b_fields::wgm1_3; // Mode 7: Fast PWM
    }

  public:
    static void enable()
    {
        ddra |= ddra_fields::pa6; // Set the port as output.
        tccr1b = ( tccr1b & ~tccr1b_fields::cs1::mask ) | get_prescalers().clock;
    }

    static void disable()
    {
        ddra &= ~( ddra_fields::pa6 );
        tccr1b = ( tccr1b & ~tccr1b_fields::cs1::mask ) | tccr1b_fields::cs1_no_clock_source_stopped;
    }
};

struct internal_bandgap
{
};

template <typename T> constexpr double reference_voltage = 0.0;
template <> constexpr double reference_voltage<internal_bandgap> = 1.1;

template <typename T> constexpr ufixed16_t reference_voltage_fp16 = ufixed16_t{ reference_voltage<T> };
template <typename T> constexpr ufixed8_t reference_voltage_fp8 = ufixed8_t{ reference_voltage<T> };

template <typename flag>
consteval ufixed8_t
voltage_value( long double voltage )
{
    if ( voltage < static_cast<double>( std::numeric_limits<ufixed8_t>::min() ) ||
         voltage > static_cast<double>( std::numeric_limits<ufixed8_t>::max() ) )
    {
        throw "Voltage out of range";
    }

    return ufixed8_t{ voltage };
}

consteval ufixed8_t operator"" _v( long double voltage )
{
    return voltage_value<internal_bandgap>( voltage );
}

class voltage_reader
{

  private:
    static ufixed16_t get_proportion()
    {
        return ufixed16_t{ ( adc & 0xff00 ) >> 8 } / ufixed16_t{ 255 }; //
    }

  public:
    static void convert()
    {
        adcsra |= adcsra_fields::adsc;
        while ( adcsra & adcsra_fields::adsc )
        { // Busy waiting loop
        }
    }

  public:
    static void init()
    {
        adcsra = adcsra_fields::aden;  // Enable ADC
        adcsrb = adcsrb_fields::adlar; // Left align bits
    }

    static void setup_for_vcc()
    {
        admux = admux_fields::refs_internal_1_1v_voltage_reference | admux_fields::mux{ 0b000000 };
    }

    static ufixed8_t read_vcc()
    {
        convert();

        constexpr ufixed16_t divider = ufixed16_t{ 11 };
        constexpr ufixed16_t multiplier = divider * reference_voltage_fp16<internal_bandgap>;

        auto result = multiplier * get_proportion();
        ufixed8_t voltage = ufixed8_t::from_fixed_point<8>( result.raw_value() );

        return voltage;
    }

    static void setup_for_vdd()
    {
        admux =
            admux_fields::refs_vcc_used_as_analog_reference_disconnected_from_pa0_aref | admux_fields::mux{ 0b100001 };
    }

    static ufixed8_t read_vdd()
    {
        // I use a very cool trick described here: https://ww1.microchip.com/downloads/en/Appnotes/00002447A.pdf. This
        // way of measuring VCC does not require any external components.
        convert();

        auto result = reference_voltage_fp16<internal_bandgap> / get_proportion();
        ufixed8_t voltage = ufixed8_t::from_fixed_point<8>( result.raw_value() );

        return voltage;
    }
};

// clang-format off
template <typename T> concept initializable = requires() {
    { T::init() };
};
// clang-format on

template <initializable... Ts>
void
initialize()
{
    ( Ts::init(), ... );
}

enum class current_state : uint8_t
{
    state_idle,
    state_armed,
    state_autonomous,
};

current_state EEMEM current_state_eemem = current_state::state_idle;

auto
get_field( auto&& value, auto&& field )
{
    using type = std::remove_cvref_t<decltype( field )>;
    return type{ ( value & field.get_mask() ) >> field.get_offset() };
}

class button
{
  public:
    static inline uint16_t debounce_state = 0;
    static inline bool pressed = false;

  private:
    static consteval auto get_prescalers()
    {
        return timer_prescalers<tim0_flag>( [ target_frequency = 500.0 ]( auto presc ) {
            return cpu_frequency / ( 2.0 * presc * target_frequency ) - 1;
        } );
    }

  public:
    static void init()
    {
        tccr0a = tccr0a_fields::wgm0_2;

        ocr0a = get_prescalers().compare;
        tccr0b = get_prescalers().clock;

        gimsk |= gimsk_fields::pcie_2;
        pcmsk1 |= ddrb_fields::pb0;
    }

    static bool is_debouncing() { return !( debounce_state == 0 ); }
    static bool is_clicked() { return std::exchange( pressed, false ); }
};

// Interrupt to enable button debounce procedure
ISR( PCINT1_vect )
{
    if ( pinb & pinb_fields::pb0 )
    { // Rising edge
        return;
    }

    timsk0 |= timsk0_fields::ocie0a;
    pcmsk1 &= ~ddrb_fields::pb0;
    button::debounce_state = 0xffff;
}

// Interrupt used to debounce a button
ISR( TIM0_COMPA_vect )
{
    button::debounce_state = ( button::debounce_state << 1 ) | get_field( pina, pina_fields::pa3 );
    if ( button::debounce_state == 0 )
    {
        timsk0 &= ~timsk0_fields::ocie0a;
        pcmsk1 |= ddrb_fields::pb0;
        button::pressed = true;
    }
}

} // namespace

int
main()
{
    cli();

    eeprom_variable_wrapper<current_state_eemem> state;
    bool configured = false;

    initialize<led_indicator, voltage_reader, buzzer, button>();

#if 0
    voltage_reader::setup_for_vcc();
    voltage_reader::convert(); // Discard initial value

    auto vcc = voltage_reader::read_vcc();

    if ( vcc > 0.5_v )
    {
        for ( uint8_t i = 0; i < 64; ++i )
        {
            auto vdd = voltage_reader::read_vcc();
            eeprom_update_byte( reinterpret_cast<uint8_t*>( i ), *reinterpret_cast<uint8_t*>( &vdd ) );
        }
    }
#endif

    auto idle_configure = [ & ]() {
        // Step 1. Clear all gpio configuration for a clean slate.
        ddra = 0;
        ddrb = 0;
        portb = 0;
        porta = 0;

        // Step 2. Initialize adc
        initialize<voltage_reader>();

        // Step 3. Set up adc for vcc reading and prepare the first reading.
        voltage_reader::setup_for_vcc();
        voltage_reader::convert(); // Discard initial reading to allow the reference to settle.
    };

    auto armed_configure = [ & ]() {
        // Step 1. Clear all gpio configuration for a clean slate.
        ddra = 0;
        ddrb = 0;
        portb = 0 | portb_fields::pb2;
        porta = 0;

        // Step 2. Initialize buzzer, led & adc.
        initialize<buzzer, led_indicator, voltage_reader>();

        // Step 3. Set up adc for vcc reading and prepare the first reading.
        voltage_reader::setup_for_vcc();
        voltage_reader::convert(); // Discard initial reading to allow the reference to settle.
    };

    auto autonomous_configure = [ & ]() {

    };

    auto idle_loop = [ & ]() {

    };

    auto armed_loop = [ & ]() {
        if ( !get_field( pinb, pinb_fields::pb2 ) )
        { // Input is low, should beep
            buzzer::enable();
            led_indicator::enable();
        } else
        {
            buzzer::disable();
            led_indicator::disable();
        }

        auto vcc = voltage_reader::read_vcc();
        constexpr ufixed8_t threshold = 3.3_v;

        if ( vcc >= threshold )
        {
            return; /* Nothing else to do */
        }

        // If we get here, then we need to transition to autonomous mode and configure necessary hardware
        state = current_state::state_autonomous;
        configured = false;
    };

    auto autonomous_loop = [ & ]() {

    };

    while ( true )
    {
        auto should_configure = !std::exchange( configured, true );

        switch ( state.get() )
        {
        case current_state::state_idle:
            if ( should_configure )
            {
                idle_configure();
            }
            idle_loop();
            break;
        case current_state::state_armed:
            if ( should_configure )
            {
                armed_configure();
            }
            armed_loop();
            break;
        case current_state::state_autonomous:
            if ( should_configure )
            {
                autonomous_configure();
            }
            autonomous_loop();
            break;
        }

        ATOMIC_BLOCK( ATOMIC_FORCEON )
        {
            if ( button::is_clicked() )
            {
                led_indicator::toggle();
            }

            bool should_power_down = !button::is_debouncing();
            set_sleep_mode( should_power_down ? SLEEP_MODE_PWR_DOWN : SLEEP_MODE_IDLE );
        }

        // Should go into sleep immediately after setting the appropriate sleep mode to avoid other
        // interrupts going in here.
        sleep_mode();
    }
}
