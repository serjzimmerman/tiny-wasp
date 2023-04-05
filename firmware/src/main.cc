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

#include <util/delay.h>

#include "attiny24a/adc.hpp"
#include "attiny24a/cpu.hpp"
#include "attiny24a/porta.hpp"

#include "attiny24a/tc0.hpp"
#include "attiny24a/tc1.hpp"

#include <fpm/fixed.hpp>

#include <algorithm>
#include <array>
#include <bit>
#include <concepts>
#include <limits>

namespace
{

using ufixed16_t = fpm::fixed<std::uint16_t, std::uint32_t, 8>;
using ufixed8_t = fpm::fixed<std::uint8_t, std::uint16_t, 4>;

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
        eeprom_write_byte( eep_ptr(), *reinterpret_cast<const uint8_t*>( &rhs ) );
        return *this;
    }

    // clang-format off
    operator T() const { auto res = eeprom_read_byte( eep_ptr() ); return *reinterpret_cast<T *>(&res); }
    eeprom_variable_wrapper& operator|=( const T& rhs ) const& { *this = +*this | rhs; return *this; }
    eeprom_variable_wrapper& operator&=( const T& rhs ) const& { *this = +*this & rhs; return *this; }
    eeprom_variable_wrapper& operator^=( const T& rhs ) const& { *this = +*this ^ rhs; return *this; }
    eeprom_variable_wrapper& operator+=( const T& rhs ) const& { *this = +*this + rhs; return *this; }
    eeprom_variable_wrapper& operator-=( const T& rhs ) const& { *this = +*this - rhs; return *this; }
    // clang-format on
};

using namespace avrcpp::attiny24a::mporta;

constexpr float cpu_frequence = F_CPU;

struct led_indicator
{
    static void init()
    {
        disable();
        ddra |= ddra_fields::pa7;
    }

    static void enable() { porta &= ~porta_fields::pa7; }
    static void disable() { porta |= porta_fields::pa7; }
    static void toggle() { porta ^= porta_fields::pa7; }
};

using namespace avrcpp::attiny24a::mtc1;
using namespace avrcpp::attiny24a::mtc0;

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

} // namespace detail

struct clock_values
{
    uint8_t compare, clock;
};

template <typename flag>
constexpr auto timer_prescaler_array = detail::timer_prescaler_array_impl<flag>::value; // Primary template

template <typename flag>
consteval clock_values
timer_prescalers( double target_frequency )
{
    auto prescalers = std::array{ 1.0, 8.0, 64.0, 256.0, 1024.0 };
    std::array<float, prescalers.size()> ocr;

    std::transform( prescalers.begin(), prescalers.end(), ocr.begin(), [ target_frequency ]( auto&& n ) {
        return cpu_frequence / ( 2.0 * n * target_frequency ) - 1;
    } );

    auto found = std::find_if( ocr.begin(), ocr.end(), []( auto&& ocr ) {
        return ( ocr >= std::numeric_limits<uint8_t>::min() ) && ( ocr <= std::numeric_limits<uint8_t>::max() );
    } );

    if ( found == ocr.end() )
    {
        throw "No suitable solution for prescaler found";
    }

    auto prescaler_array = timer_prescaler_array<flag>;
    auto index = std::distance( ocr.begin(), found );
    return clock_values{ static_cast<uint8_t>( *found ), prescaler_array.at( index ) };
}

struct buzzer
{
    static constexpr float target_frequency = 2700.0f;

    static consteval auto get_tccr0a_value()
    {
        auto val = tccr1a_register::register_type{ 0 };

        val |= tccr1a_fields::wgm1_3;  // Mode 7: Fast PWM
        val |= tccr1a_fields::com1a_1; // Toggle OC0A on compare match

        return val;
    }

    static consteval auto get_tccr0b_value()
    {
        auto val = tccr1b_register::register_type{ 0 };

        // Mode 7: Fast PWM
        val |= tccr1b_fields::wgm1_3;

        return val;
    }

    static void init()
    {
        ddra |= ddra_fields::pa6; // Set the port as output.
        ocr1a = timer_prescalers<tim1_flag>( target_frequency ).compare;
        tccr1a = get_tccr0a_value();
        tccr1b = get_tccr0b_value();
    }

    static void enable()
    {
        constexpr auto clock = timer_prescalers<tim1_flag>( target_frequency ).clock;
        tccr1b |= clock;
    }

    static void disable() { tccr1b &= ~tccr1b_fields::cs1::mask; }
};

using namespace avrcpp::attiny24a::madc;

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

struct voltage_reader
{
  public:
    static constexpr ufixed16_t divider = ufixed16_t{ 11 };
    static constexpr ufixed16_t multiplier = divider * reference_voltage_fp16<internal_bandgap>;

  private:
    static ufixed16_t get_proportion()
    {
        return ufixed16_t{ ( adc & 0xff00 ) >> 8 } / ufixed16_t{ 255 }; //
    }

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

    static ufixed8_t read_vcc()
    {
        admux = admux_fields::refs_internal_1_1v_voltage_reference | admux_fields::mux{ 0b000000 };
        _delay_us( 100 ); // Necessary for the internal reference to stabilize. A 100us delay should do.
        convert();

        auto result = multiplier * get_proportion();
        ufixed8_t voltage = ufixed8_t::from_fixed_point<8>( result.raw_value() );

        return voltage;
    }

    static ufixed8_t read_vdd()
    {
        // I use a very cool trick described here: https://ww1.microchip.com/downloads/en/Appnotes/00002447A.pdf. This
        // way of measuring VCC does not require any external components.
        admux =
            admux_fields::refs_vcc_used_as_analog_reference_disconnected_from_pa0_aref | admux_fields::mux{ 0b100001 };
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

using namespace avrcpp::attiny24a::mcpu;

enum class current_state : uint8_t
{
    state_idle,
    state_armed,
    state_autonomous,
};

bool
is_charging()
{
    return !( pina >> porta_fields::pa2 );
}

} // namespace

current_state EEMEM current_state_eemem = current_state::state_idle;

int
main()
{
    initialize<led_indicator, buzzer, voltage_reader>();

    buzzer::enable();
    led_indicator::enable();

    eeprom_variable_wrapper<current_state_eemem> state_accessor;

    if ( state_accessor != current_state::state_idle )
    {
        for ( uint8_t start = 0, finish = 2; start != finish; ++start )
        {
            for ( uint8_t i = 0; i < 2; ++i )
            {
                _delay_ms( 500 );
                led_indicator::toggle();
                ddra ^= ddra_fields::pa6;
            }
        }
    }

    _delay_ms( 1000 );
    buzzer::disable();
    led_indicator::disable();

    for ( uint8_t i = 0; i < 64; ++i )
    {
        auto vdd = voltage_reader::read_vdd();
        eeprom_update_byte( reinterpret_cast<uint8_t*>( i ), *reinterpret_cast<uint8_t*>( &vdd ) );
    }

    while ( true )
    {
        auto vdd = voltage_reader::read_vdd();
        if ( !is_charging() && vdd <= 3.20_v )
        {
            led_indicator::toggle();
            _delay_ms( 200 );
        }
    }
}
