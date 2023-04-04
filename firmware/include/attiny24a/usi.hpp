
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

namespace avrcpp::attiny24a::musi
{

// USI Buffer Register
using usibr_register = avrcpp::register_wrapper<0x30, 1, avrcpp::read_write_flag>;

constexpr auto usibr = usibr_register{};

// USI Control Register
using usicr_register = avrcpp::register_wrapper<0x2d, 1, avrcpp::read_write_flag>;

namespace usicr_fields
{

// Toggle Clock Port Pin
constexpr auto usitc = avrcpp::register_field<usicr_register, 0, 1>{ 1 };

// Clock Strobe
constexpr auto usiclk = avrcpp::register_field<usicr_register, 1, 1>{ 1 };

constexpr auto usics_0 = avrcpp::register_field<usicr_register, 2, 2>{ 0 };

constexpr auto usics_1 = avrcpp::register_field<usicr_register, 2, 2>{ 1 };

constexpr auto usics_2 = avrcpp::register_field<usicr_register, 2, 2>{ 2 };

constexpr auto usics_3 = avrcpp::register_field<usicr_register, 2, 2>{ 3 };

using usics = avrcpp::register_field<usicr_register, 2, 2>;

// Normal Operation
constexpr auto usiwm_normal_operation = avrcpp::register_field<usicr_register, 4, 2>{ 0 };

// Three-Wire Mode
constexpr auto usiwm_three_wire_mode = avrcpp::register_field<usicr_register, 4, 2>{ 1 };

// Two-Wire Mode
constexpr auto usiwm_two_wire_mode = avrcpp::register_field<usicr_register, 4, 2>{ 2 };

// Two-Wire Mode Held Low
constexpr auto usiwm_two_wire_mode_held_low = avrcpp::register_field<usicr_register, 4, 2>{ 3 };

using usiwm = avrcpp::register_field<usicr_register, 4, 2>;

// Counter Overflow Interrupt Enable
constexpr auto usioie = avrcpp::register_field<usicr_register, 6, 1>{ 1 };

// Start Condition Interrupt Enable
constexpr auto usisie = avrcpp::register_field<usicr_register, 7, 1>{ 1 };

} // namespace usicr_fields

constexpr auto usicr = usicr_register{};

// USI Data Register
using usidr_register = avrcpp::register_wrapper<0x2f, 1, avrcpp::read_write_flag>;

constexpr auto usidr = usidr_register{};

// USI Status Register
using usisr_register = avrcpp::register_wrapper<0x2e, 1, avrcpp::read_write_flag>;

namespace usisr_fields
{

constexpr auto usicnt_0 = avrcpp::register_field<usisr_register, 0, 4>{ 0 };

constexpr auto usicnt_1 = avrcpp::register_field<usisr_register, 0, 4>{ 1 };

constexpr auto usicnt_2 = avrcpp::register_field<usisr_register, 0, 4>{ 2 };

constexpr auto usicnt_3 = avrcpp::register_field<usisr_register, 0, 4>{ 3 };

constexpr auto usicnt_4 = avrcpp::register_field<usisr_register, 0, 4>{ 4 };

constexpr auto usicnt_5 = avrcpp::register_field<usisr_register, 0, 4>{ 5 };

constexpr auto usicnt_6 = avrcpp::register_field<usisr_register, 0, 4>{ 6 };

constexpr auto usicnt_7 = avrcpp::register_field<usisr_register, 0, 4>{ 7 };

constexpr auto usicnt_8 = avrcpp::register_field<usisr_register, 0, 4>{ 8 };

constexpr auto usicnt_9 = avrcpp::register_field<usisr_register, 0, 4>{ 9 };

constexpr auto usicnt_10 = avrcpp::register_field<usisr_register, 0, 4>{ 10 };

constexpr auto usicnt_11 = avrcpp::register_field<usisr_register, 0, 4>{ 11 };

constexpr auto usicnt_12 = avrcpp::register_field<usisr_register, 0, 4>{ 12 };

constexpr auto usicnt_13 = avrcpp::register_field<usisr_register, 0, 4>{ 13 };

constexpr auto usicnt_14 = avrcpp::register_field<usisr_register, 0, 4>{ 14 };

constexpr auto usicnt_15 = avrcpp::register_field<usisr_register, 0, 4>{ 15 };

using usicnt = avrcpp::register_field<usisr_register, 0, 4>;

// Data Output Collision
constexpr auto usidc = avrcpp::register_field<usisr_register, 4, 1>{ 1 };

// Stop Condition Flag
constexpr auto usipf = avrcpp::register_field<usisr_register, 5, 1>{ 1 };

// Counter Overflow Interrupt Flag
constexpr auto usioif = avrcpp::register_field<usisr_register, 6, 1>{ 1 };

// Start Condition Interrupt Flag
constexpr auto usisif = avrcpp::register_field<usisr_register, 7, 1>{ 1 };

} // namespace usisr_fields

constexpr auto usisr = usisr_register{};

} // namespace avrcpp::attiny24a::musi