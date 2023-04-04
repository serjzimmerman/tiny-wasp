
/** ----------------------------------------------------------------------------'
 * "THE BEER-WARE LICENSE" (Revision 42):'
 * <tsimmerman.ss@phystech.edu> wrote this file.  As long'
 * as you retain this notice you can do whatever you want with this stuff. If we'
 * meet some day, and you think this stuff is worth it, you can buy me a beer in'
 * return.'
 * ----------------------------------------------------------------------------'
 */

#pragma once

#include "avrcpp/register.hpp"

namespace avrcpp::attiny24a::mtc0
{

// General Timer/Counter Control Register
using gtccr_register = avrcpp::register_wrapper<0x43, 1, avrcpp::read_write_flag>;

namespace gtccr_fields
{

// Prescaler Reset Timer/CounterN
constexpr auto psr10 = avrcpp::register_field<gtccr_register, 0, 1>{ 1 };

// Timer/Counter Synchronization Mode
constexpr auto tsm = avrcpp::register_field<gtccr_register, 7, 1>{ 1 };

} // namespace gtccr_fields

constexpr auto gtccr = gtccr_register{};

// Timer/Counter0 Output Compare Register A
using ocr0a_register = avrcpp::register_wrapper<0x56, 1, avrcpp::read_write_flag>;

constexpr auto ocr0a = ocr0a_register{};

// Timer/Counter0 Output Compare Register B
using ocr0b_register = avrcpp::register_wrapper<0x5c, 1, avrcpp::read_write_flag>;

constexpr auto ocr0b = ocr0b_register{};

// Timer/Counter  Control Register A
using tccr0a_register = avrcpp::register_wrapper<0x50, 1, avrcpp::read_write_flag>;

namespace tccr0a_fields
{

constexpr auto wgm0_0 = avrcpp::register_field<tccr0a_register, 0, 2>{ 0 };

constexpr auto wgm0_1 = avrcpp::register_field<tccr0a_register, 0, 2>{ 1 };

constexpr auto wgm0_2 = avrcpp::register_field<tccr0a_register, 0, 2>{ 2 };

constexpr auto wgm0_3 = avrcpp::register_field<tccr0a_register, 0, 2>{ 3 };

using wgm0 = avrcpp::register_field<tccr0a_register, 0, 2>;

constexpr auto com0b_0 = avrcpp::register_field<tccr0a_register, 4, 2>{ 0 };

constexpr auto com0b_1 = avrcpp::register_field<tccr0a_register, 4, 2>{ 1 };

constexpr auto com0b_2 = avrcpp::register_field<tccr0a_register, 4, 2>{ 2 };

constexpr auto com0b_3 = avrcpp::register_field<tccr0a_register, 4, 2>{ 3 };

using com0b = avrcpp::register_field<tccr0a_register, 4, 2>;

constexpr auto com0a_0 = avrcpp::register_field<tccr0a_register, 6, 2>{ 0 };

constexpr auto com0a_1 = avrcpp::register_field<tccr0a_register, 6, 2>{ 1 };

constexpr auto com0a_2 = avrcpp::register_field<tccr0a_register, 6, 2>{ 2 };

constexpr auto com0a_3 = avrcpp::register_field<tccr0a_register, 6, 2>{ 3 };

using com0a = avrcpp::register_field<tccr0a_register, 6, 2>;

} // namespace tccr0a_fields

constexpr auto tccr0a = tccr0a_register{};

// Timer/Counter Control Register B
using tccr0b_register = avrcpp::register_wrapper<0x53, 1, avrcpp::read_write_flag>;

namespace tccr0b_fields
{

// No Clock Source (Stopped)
constexpr auto cs0_no_clock_source_stopped = avrcpp::register_field<tccr0b_register, 0, 3>{ 0 };

// Running, No Prescaling
constexpr auto cs0_running_no_prescaling = avrcpp::register_field<tccr0b_register, 0, 3>{ 1 };

// Running, CLK/8
constexpr auto cs0_running_clk_8 = avrcpp::register_field<tccr0b_register, 0, 3>{ 2 };

// Running, CLK/64
constexpr auto cs0_running_clk_64 = avrcpp::register_field<tccr0b_register, 0, 3>{ 3 };

// Running, CLK/256
constexpr auto cs0_running_clk_256 = avrcpp::register_field<tccr0b_register, 0, 3>{ 4 };

// Running, CLK/1024
constexpr auto cs0_running_clk_1024 = avrcpp::register_field<tccr0b_register, 0, 3>{ 5 };

// Running, ExtClk Tn Falling Edge
constexpr auto cs0_running_extclk_tn_falling_edge = avrcpp::register_field<tccr0b_register, 0, 3>{ 6 };

// Running, ExtClk Tn Rising Edge
constexpr auto cs0_running_extclk_tn_rising_edge = avrcpp::register_field<tccr0b_register, 0, 3>{ 7 };

using cs0 = avrcpp::register_field<tccr0b_register, 0, 3>;

// Waveform Generation Mode bit 2
constexpr auto wgm02 = avrcpp::register_field<tccr0b_register, 3, 1>{ 1 };

// Force Output Compare B
constexpr auto foc0b = avrcpp::register_field<tccr0b_register, 6, 1>{ 1 };

// Force Output Compare A
constexpr auto foc0a = avrcpp::register_field<tccr0b_register, 7, 1>{ 1 };

} // namespace tccr0b_fields

constexpr auto tccr0b = tccr0b_register{};

// Timer/Counter0
using tcnt0_register = avrcpp::register_wrapper<0x52, 1, avrcpp::read_write_flag>;

constexpr auto tcnt0 = tcnt0_register{};

// Timer/Counter0 Interrupt Flag Register
using tifr0_register = avrcpp::register_wrapper<0x58, 1, avrcpp::read_write_flag>;

namespace tifr0_fields
{

// Timer/Counter0 Overflow Flag
constexpr auto tov0 = avrcpp::register_field<tifr0_register, 0, 1>{ 1 };

// Timer/Counter0 Output Compare Flag A
constexpr auto ocf0a = avrcpp::register_field<tifr0_register, 1, 1>{ 1 };

// Timer/Counter0 Output Compare Flag B
constexpr auto ocf0b = avrcpp::register_field<tifr0_register, 2, 1>{ 1 };

} // namespace tifr0_fields

constexpr auto tifr0 = tifr0_register{};

// Timer/Counter Interrupt Mask Register
using timsk0_register = avrcpp::register_wrapper<0x59, 1, avrcpp::read_write_flag>;

namespace timsk0_fields
{

// Timer/Counter0 Overflow Interrupt Enable
constexpr auto toie0 = avrcpp::register_field<timsk0_register, 0, 1>{ 1 };

// Timer/Counter0 Output Compare Match A Interrupt Enable
constexpr auto ocie0a = avrcpp::register_field<timsk0_register, 1, 1>{ 1 };

// Timer/Counter0 Output Compare Match B Interrupt Enable
constexpr auto ocie0b = avrcpp::register_field<timsk0_register, 2, 1>{ 1 };

} // namespace timsk0_fields

constexpr auto timsk0 = timsk0_register{};

} // namespace avrcpp::attiny24a::mtc0