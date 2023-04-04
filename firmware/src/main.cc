/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <tsimmerman.ss@phystech.edu> wrote this file.  As long
 * as you retain this notice you can do whatever you want with this stuff. If we
 * meet some day, and you think this stuff is worth it, you can buy me a beer in
 * return.
 * ----------------------------------------------------------------------------
 */

#include <avr/io.h>
#include <util/delay.h>

#include "attiny24a/ac.hpp"
#include "attiny24a/adc.hpp"
#include "attiny24a/boot_load.hpp"
#include "attiny24a/eeprom.hpp"
#include "attiny24a/porta.hpp"
#include "attiny24a/tc0.hpp"
#include "attiny24a/tc1.hpp"

#include <algorithm>
#include <array>

namespace
{

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

struct buzzer
{
    static constexpr float target_frequency = 2700.0f;

    struct clock_values
    {
        ocr1a_register::register_type compare;
        tccr1b_fields::cs1 clock;
    };

    static consteval clock_values get_output_compare()
    {
        auto prescalers = std::array{ 1.0, 8.0, 64.0, 256.0, 1024.0 };
        std::array<float, prescalers.size()> ocr;

        std::transform( prescalers.begin(), prescalers.end(), ocr.begin(), []( auto&& n ) {
            return cpu_frequence / ( 2.0 * n * target_frequency ) - 1;
        } );

        auto found =
            std::find_if( ocr.begin(), ocr.end(), []( auto&& ocr ) { return ( ocr >= 0.0 ) && ( ocr <= 255.0 ); } );

        if ( found == ocr.end() )
        {
            throw "No suitable solution for prescaler found";
        }

        auto index = std::distance( ocr.begin(), found );

        using namespace tccr1b_fields;
        auto clock = std::array{
            cs1_running_no_prescaling,
            cs1_running_clk_8,
            cs1_running_clk_64,
            cs1_running_clk_64,
            cs1_running_clk_256,
            cs1_running_clk_1024 };

        return clock_values{ static_cast<ocr1a_register::register_type>( *found ), clock.at( index ) };
    }

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
        constexpr auto compare = get_output_compare().compare;
        util::static_print<compare>();

        ddra |= ddra_fields::pa6; // Set the port as output.
        ocr1a = compare;
        tccr1a = get_tccr0a_value();
        tccr1b = get_tccr0b_value();
    }

    static ALWAYS_INLINE void enable()
    {
        constexpr auto clock = get_output_compare().clock;
        util::static_print<+clock>();
        tccr1b |= clock;
    }

    static ALWAYS_INLINE void disable() { tccr1b &= ~tccr1b_fields::cs1::mask; }
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

} // namespace

int
main()
{
    initialize<led_indicator, buzzer>();

    buzzer::enable();
    led_indicator::enable();

    while ( 1 )
    {
        _delay_ms( 500 );
        led_indicator::toggle();
        ddra ^= ddra_fields::pa6;
    }
}
