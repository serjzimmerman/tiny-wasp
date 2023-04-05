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

#include <algorithm>
#include <array>
#include <bit>
#include <concepts>
#include <limits>

namespace
{

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

    ALWAYS_INLINE eeprom_variable_wrapper& operator=( const T& rhs )
    {
        eeprom_write_byte( eep_ptr(), *reinterpret_cast<const uint8_t*>( &rhs ) );
        return *this;
    }

    // clang-format off
    ALWAYS_INLINE operator T() const { auto res = eeprom_read_byte( eep_ptr() ); return *reinterpret_cast<T *>(&res); }
    ALWAYS_INLINE eeprom_variable_wrapper& operator|=( const T& rhs ) const& { *this = +*this | rhs; return *this; }
    ALWAYS_INLINE eeprom_variable_wrapper& operator&=( const T& rhs ) const& { *this = +*this & rhs; return *this; }
    ALWAYS_INLINE eeprom_variable_wrapper& operator^=( const T& rhs ) const& { *this = +*this ^ rhs; return *this; }
    ALWAYS_INLINE eeprom_variable_wrapper& operator+=( const T& rhs ) const& { *this = +*this + rhs; return *this; }
    ALWAYS_INLINE eeprom_variable_wrapper& operator-=( const T& rhs ) const& { *this = +*this - rhs; return *this; }
    // clang-format on
};

using namespace avrcpp::attiny24a::mporta;

constexpr float cpu_frequence = F_CPU;

struct led_indicator
{
    static ALWAYS_INLINE void init()
    {
        disable();
        ddra |= ddra_fields::pa7;
    }

    static ALWAYS_INLINE void enable() { porta &= ~porta_fields::pa7; }
    static ALWAYS_INLINE void disable() { porta |= porta_fields::pa7; }
    static ALWAYS_INLINE void toggle() { porta ^= porta_fields::pa7; }
};

using namespace avrcpp::attiny24a::mtc1;
using namespace avrcpp::attiny24a::mtc0;

struct tim0_flag;
struct tim1_flag;

template <typename flag> constexpr auto timer_prescaler_array = 0; // Primary template

template <>
constexpr auto timer_prescaler_array<tim0_flag> = std::array{
    tccr0b_fields::cs0_running_no_prescaling,
    tccr0b_fields::cs0_running_clk_8,
    tccr0b_fields::cs0_running_clk_64,
    tccr0b_fields::cs0_running_clk_64,
    tccr0b_fields::cs0_running_clk_256,
    tccr0b_fields::cs0_running_clk_1024 };

template <>
constexpr auto timer_prescaler_array<tim1_flag> = std::array{
    tccr1b_fields::cs1_running_no_prescaling,
    tccr1b_fields::cs1_running_clk_8,
    tccr1b_fields::cs1_running_clk_64,
    tccr1b_fields::cs1_running_clk_64,
    tccr1b_fields::cs1_running_clk_256,
    tccr1b_fields::cs1_running_clk_1024 };

struct clock_values
{
    uint8_t compare, clock;
};

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

    static ALWAYS_INLINE void init()
    {
        constexpr auto compare = timer_prescalers<tim1_flag>( target_frequency ).compare;
        util::static_print<compare>();

        ddra |= ddra_fields::pa6; // Set the port as output.
        ocr1a = compare;
        tccr1a = get_tccr0a_value();
        tccr1b = get_tccr0b_value();
    }

    static ALWAYS_INLINE void enable()
    {
        constexpr auto clock = timer_prescalers<tim1_flag>( target_frequency ).clock;
        util::static_print<+clock>();
        tccr1b |= clock;
    }

    static ALWAYS_INLINE void disable() { tccr1b &= ~tccr1b_fields::cs1::mask; }
};

using namespace avrcpp::attiny24a::madc;

struct voltage_reader
{
    static ALWAYS_INLINE void init()
    {
        adcsra = adcsra_fields::aden;
        admux = admux_fields::refs_internal_1_1v_voltage_reference | admux_fields::mux{ 0b000000 };
    }

    static ALWAYS_INLINE uint16_t read_vcc()
    {
        adcsra |= adcsra_fields::adsc;
        while ( adcsra & adcsra_fields::adsc )
        {
            asm volatile( "" ); // Busy wait loop
        }
        return adc;
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

    while ( true )
    {
        auto vcc = voltage_reader::read_vcc();
        if ( !is_charging() && vcc <= 330 )
        {
            led_indicator::toggle();
            _delay_ms( 200 );
        }
    }
}
