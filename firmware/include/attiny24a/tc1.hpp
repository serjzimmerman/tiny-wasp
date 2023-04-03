
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

namespace avrcpp::attiny24a::mtc1
{

// Timer/Counter1 Input Capture Register  Bytes
using icr1_register = avrcpp::register_wrapper<0x44, 2, avrcpp::read_write_flag>;

constexpr auto icr1 = icr1_register{};

// Timer/Counter1 Output Compare Register A  Bytes
using ocr1a_register = avrcpp::register_wrapper<0x4a, 2, avrcpp::read_write_flag>;

constexpr auto ocr1a = ocr1a_register{};

// Timer/Counter1 Output Compare Register B  Bytes
using ocr1b_register = avrcpp::register_wrapper<0x48, 2, avrcpp::read_write_flag>;

constexpr auto ocr1b = ocr1b_register{};

// Timer/Counter1 Control Register A
using tccr1a_register = avrcpp::register_wrapper<0x4f, 1, avrcpp::read_write_flag>;

namespace tccr1a_fields
{

} // namespace tccr1a_fields

constexpr auto tccr1a = tccr1a_register{};

// Timer/Counter1 Control Register B
using tccr1b_register = avrcpp::register_wrapper<0x4e, 1, avrcpp::read_write_flag>;

namespace tccr1b_fields
{

// No Clock Source (Stopped)
constexpr auto cs1_no_clock_source_stopped = avrcpp::register_field<tccr1b_register, 0, 3>{ 0 };

// Running, No Prescaling
constexpr auto cs1_running_no_prescaling = avrcpp::register_field<tccr1b_register, 0, 3>{ 1 };

// Running, CLK/8
constexpr auto cs1_running_clk_8 = avrcpp::register_field<tccr1b_register, 0, 3>{ 2 };

// Running, CLK/64
constexpr auto cs1_running_clk_64 = avrcpp::register_field<tccr1b_register, 0, 3>{ 3 };

// Running, CLK/256
constexpr auto cs1_running_clk_256 = avrcpp::register_field<tccr1b_register, 0, 3>{ 4 };

// Running, CLK/1024
constexpr auto cs1_running_clk_1024 = avrcpp::register_field<tccr1b_register, 0, 3>{ 5 };

// Running, ExtClk Tn Falling Edge
constexpr auto cs1_running_extclk_tn_falling_edge = avrcpp::register_field<tccr1b_register, 0, 3>{ 6 };

// Running, ExtClk Tn Rising Edge
constexpr auto cs1_running_extclk_tn_rising_edge = avrcpp::register_field<tccr1b_register, 0, 3>{ 7 };

// Input Capture 1 Edge Select
constexpr auto ices1 = avrcpp::register_field<tccr1b_register, 6, 1>{ 1 };

// Input Capture 1 Noise Canceler
constexpr auto icnc1 = avrcpp::register_field<tccr1b_register, 7, 1>{ 1 };

} // namespace tccr1b_fields

constexpr auto tccr1b = tccr1b_register{};

// Timer/Counter1 Control Register C
using tccr1c_register = avrcpp::register_wrapper<0x42, 1, avrcpp::read_write_flag>;

namespace tccr1c_fields
{

// Force Output Compare for Channel B
constexpr auto foc1b = avrcpp::register_field<tccr1c_register, 6, 1>{ 1 };

// Force Output Compare for Channel A
constexpr auto foc1a = avrcpp::register_field<tccr1c_register, 7, 1>{ 1 };

} // namespace tccr1c_fields

constexpr auto tccr1c = tccr1c_register{};

// Timer/Counter1  Bytes
using tcnt1_register = avrcpp::register_wrapper<0x4c, 2, avrcpp::read_write_flag>;

constexpr auto tcnt1 = tcnt1_register{};

// Timer/Counter Interrupt Flag register
using tifr1_register = avrcpp::register_wrapper<0x2b, 1, avrcpp::read_write_flag>;

namespace tifr1_fields
{

// Timer/Counter1 Overflow Flag
constexpr auto tov1 = avrcpp::register_field<tifr1_register, 0, 1>{ 1 };

// Timer/Counter1 Output Compare A Match Flag
constexpr auto ocf1a = avrcpp::register_field<tifr1_register, 1, 1>{ 1 };

// Timer/Counter1 Output Compare B Match Flag
constexpr auto ocf1b = avrcpp::register_field<tifr1_register, 2, 1>{ 1 };

// Timer/Counter1 Input Capture Flag
constexpr auto icf1 = avrcpp::register_field<tifr1_register, 5, 1>{ 1 };

} // namespace tifr1_fields

constexpr auto tifr1 = tifr1_register{};

// Timer/Counter1 Interrupt Mask Register
using timsk1_register = avrcpp::register_wrapper<0x2c, 1, avrcpp::read_write_flag>;

namespace timsk1_fields
{

// Timer/Counter1 Overflow Interrupt Enable
constexpr auto toie1 = avrcpp::register_field<timsk1_register, 0, 1>{ 1 };

// Timer/Counter1 Output Compare A Match Interrupt Enable
constexpr auto ocie1a = avrcpp::register_field<timsk1_register, 1, 1>{ 1 };

// Timer/Counter1 Output Compare B Match Interrupt Enable
constexpr auto ocie1b = avrcpp::register_field<timsk1_register, 2, 1>{ 1 };

// Timer/Counter1 Input Capture Interrupt Enable
constexpr auto icie1 = avrcpp::register_field<timsk1_register, 5, 1>{ 1 };

} // namespace timsk1_fields

constexpr auto timsk1 = timsk1_register{};

} // namespace avrcpp::attiny24a::mtc1