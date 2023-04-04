/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <tsimmerman.ss@phystech.edu> wrote this file.  As long
 * as you retain this notice you can do whatever you want with this stuff. If we
 * meet some day, and you think this stuff is worth it, you can buy me a beer in
 * return.
 * ----------------------------------------------------------------------------
 */

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
        reset();
        ddra |= ddra_fields::pa7;
    }

    static ALWAYS_INLINE void set() { porta |= porta_fields::pa7; }
    static ALWAYS_INLINE void reset() { porta &= ~porta_fields::pa7; }
    static ALWAYS_INLINE void toggle() { porta ^= porta_fields::pa7; }
};

using namespace avrcpp::attiny24a::mtc0;

struct buzzer
{
    static constexpr float target_frequency = 2700.0f;

    struct clock_values
    {
        ocr0a_register::register_type compare;
        tccr0b_fields::cs0 clock;
    };

    static consteval clock_values get_output_compare()
    {
        auto prescalers = std::array{ 1.0f, 8.0f, 64.0f, 256.0f, 1024.0f };
        std::array<float, prescalers.size()> ocr;

        std::transform( prescalers.begin(), prescalers.end(), ocr.begin(), []( auto&& n ) {
            return cpu_frequence / ( 2.0f * n * target_frequency ) - 1;
        } );

        auto found =
            std::find_if( ocr.begin(), ocr.end(), []( auto&& ocr ) { return ( ocr >= 0.0f ) && ( ocr <= 255.0f ); } );

        if ( found == ocr.end() )
        {
            throw "No suitable solution for prescaler found";
        }

        auto index = std::distance( ocr.begin(), found );

        using namespace tccr0b_fields;
        auto clock = std::array{
            cs0_running_no_prescaling,
            cs0_running_clk_8,
            cs0_running_clk_64,
            cs0_running_clk_64,
            cs0_running_clk_256,
            cs0_running_clk_1024 };

        return clock_values{ static_cast<ocr0a_register::register_type>( *found ), clock.at( index ) };
    }

    consteval auto get_tccr0a_value()
    {
        auto val = tccr0a_register::register_type{ 0 };

        val |= tccr0a_fields::wgm0_3;  // Mode 7: Fast PWM
        val |= tccr0a_fields::com0a_1; // Toggle OC0A on compare match

        return val;
    }

    consteval auto get_tccr0b_value()
    {
        auto val = tccr0b_register::register_type{};

        // Mode 7: Fast PWM
        val |= tccr0b_fields::wgm02;

        return val;
    }

    static ALWAYS_INLINE void init()
    {
        ddra |= ddra_fields::pa6; // Set the port as output.

        constexpr clock_values prescalers = get_output_compare();
        util::static_print<prescalers.compare>();
        util::static_print<prescalers.clock>();

        // ocr0a = get_output_compare();
        tccr0a_fields::wgm0_3;
        tccr0b_fields::wgm02;
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

} // namespace

int
main()
{
    initialize<led_indicator>();

    while ( 1 )
    {
        _delay_ms( 100 );
        led_indicator::toggle();
    }
}
