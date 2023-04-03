
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

namespace avrcpp::attiny24a::mfuse
{

// No Description.
using extended_register = avrcpp::register_wrapper<0x2, 1, avrcpp::read_write_flag>;

namespace extended_fields
{

// Self Programming enable
constexpr auto selfprgen = avrcpp::register_field<extended_register, 0, 1>{ 1 };

} // namespace extended_fields

constexpr auto extended = extended_register{};

// No Description.
using high_register = avrcpp::register_wrapper<0x1, 1, avrcpp::read_write_flag>;

namespace high_fields
{

// Brown-out detection at VCC=4.3 V
constexpr auto bodlevel_4v3 = avrcpp::register_field<high_register, 0, 3>{ 0 };

// Brown-out detection at VCC=2.7 V
constexpr auto bodlevel_2v7 = avrcpp::register_field<high_register, 0, 3>{ 0 };

// Brown-out detection at VCC=1.8 V
constexpr auto bodlevel_1v8 = avrcpp::register_field<high_register, 0, 3>{ 0 };

// Brown-out detection disabled
constexpr auto bodlevel_disabled = avrcpp::register_field<high_register, 0, 3>{ 0 };

// Preserve EEPROM through the Chip Erase cycle
constexpr auto eesave = avrcpp::register_field<high_register, 3, 1>{ 1 };

// Watch-dog Timer always on
constexpr auto wdton = avrcpp::register_field<high_register, 4, 1>{ 1 };

// Serial program downloading (SPI) enabled
constexpr auto spien = avrcpp::register_field<high_register, 5, 1>{ 1 };

// Debug Wire enable
constexpr auto dwen = avrcpp::register_field<high_register, 6, 1>{ 1 };

// Reset Disabled (Enable PB3 as i/o pin)
constexpr auto rstdisbl = avrcpp::register_field<high_register, 7, 1>{ 1 };

} // namespace high_fields

constexpr auto high = high_register{};

// No Description.
using low_register = avrcpp::register_wrapper<0x0, 1, avrcpp::read_write_flag>;

namespace low_fields
{

// Ext. Clock; Start-up time PWRDWN/RESET: 6 CK/14 CK + 0 ms
constexpr auto sut_cksel_extclk_6ck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Int. RC Osc. 8 MHz; Start-up time PWRDWN/RESET: 6 CK/14 CK + 0 ms
constexpr auto sut_cksel_intrcosc_8mhz_6ck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// WD. Osc. 128 kHz; Start-up time PWRDWN/RESET: 6 CK/14 CK + 0 ms
constexpr auto sut_cksel_wdosc_128khz_6ck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Low-Freq. Crystal; Start-up time PWRDWN/RESET: 1K CK/14 CK + 0 ms
constexpr auto sut_cksel_extlofxtal_1kck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.4-0.9 MHz; Start-up time PWRDWN/RESET: 258 CK/14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_0mhz4_0mhz9_258ck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.4-0.9 MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 65 ms
constexpr auto sut_cksel_extxosc_0mhz4_0mhz9_1kck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.9-3.0 MHz; Start-up time PWRDWN/RESET: 258 CK/14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_0mhz9_3mhz_258ck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.9-3.0 MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 65 ms
constexpr auto sut_cksel_extxosc_0mhz9_3mhz_1kck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 3.0-8.0 MHz; Start-up time PWRDWN/RESET: 258 CK/14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_3mhz_8mhz_258ck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 3.0-8.0 MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 65 ms
constexpr auto sut_cksel_extxosc_3mhz_8mhz_1kck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 8.0-    MHz; Start-up time PWRDWN/RESET: 258 CK/14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_8mhz_xx_258ck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 8.0-    MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 65 ms
constexpr auto sut_cksel_extxosc_8mhz_xx_1kck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Clock; Start-up time PWRDWN/RESET: 6 CK/14 CK + 4.1 ms
constexpr auto sut_cksel_extclk_6ck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Int. RC Osc. 8 MHz; Start-up time PWRDWN/RESET: 6 CK/14 CK + 4 ms
constexpr auto sut_cksel_intrcosc_8mhz_6ck_14ck_4ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// WD. Osc. 128 kHz; Start-up time PWRDWN/RESET: 6 CK/14 CK + 4 ms
constexpr auto sut_cksel_wdosc_128khz_6ck_14ck_4ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Low-Freq. Crystal; Start-up time PWRDWN/RESET: 1K CK/14 CK + 4 ms
constexpr auto sut_cksel_extlofxtal_1kck_14ck_4ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.4-0.9 MHz; Start-up time PWRDWN/RESET: 258 CK/14 CK + 65 ms
constexpr auto sut_cksel_extxosc_0mhz4_0mhz9_258ck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.4-0.9 MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 0 ms
constexpr auto sut_cksel_extxosc_0mhz4_0mhz9_16kck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.9-3.0 MHz; Start-up time PWRDWN/RESET: 258 CK/14 CK + 65 ms
constexpr auto sut_cksel_extxosc_0mhz9_3mhz_258ck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.9-3.0 MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 0 ms
constexpr auto sut_cksel_extxosc_0mhz9_3mhz_16kck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 3.0-8.0 MHz; Start-up time PWRDWN/RESET: 258 CK/14 CK + 65 ms
constexpr auto sut_cksel_extxosc_3mhz_8mhz_258ck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 3.0-8.0 MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 0 ms
constexpr auto sut_cksel_extxosc_3mhz_8mhz_16kck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 8.0-    MHz; Start-up time PWRDWN/RESET: 258 CK/14 CK + 65 ms
constexpr auto sut_cksel_extxosc_8mhz_xx_258ck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 8.0-    MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 0 ms
constexpr auto sut_cksel_extxosc_8mhz_xx_16kck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Clock; Start-up time PWRDWN/RESET: 6 CK/14 CK + 65 ms
constexpr auto sut_cksel_extclk_6ck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Int. RC Osc. 8 MHz; Start-up time PWRDWN/RESET: 6 CK/14 CK + 64 ms; default value
constexpr auto sut_cksel_intrcosc_8mhz_6ck_14ck_64ms_default = avrcpp::register_field<low_register, 0, 6>{ 0 };

// WD. Osc. 128 kHz; Start-up time PWRDWN/RESET: 6 CK/14 CK + 64 ms
constexpr auto sut_cksel_wdosc_128khz_6ck_14ck_64ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Low-Freq. Crystal; Start-up time PWRDWN/RESET: 32K CK/14 CK + 64 ms
constexpr auto sut_cksel_extlofxtal_32kck_14ck_64ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.4-0.9 MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 0 ms
constexpr auto sut_cksel_extxosc_0mhz4_0mhz9_1kck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.4-0.9 MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_0mhz4_0mhz9_16kck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.9-3.0 MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 0 ms
constexpr auto sut_cksel_extxosc_0mhz9_3mhz_1kck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.9-3.0 MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_0mhz9_3mhz_16kck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 3.0-8.0 MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 0 ms
constexpr auto sut_cksel_extxosc_3mhz_8mhz_1kck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 3.0-8.0 MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_3mhz_8mhz_16kck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 8.0-    MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 0 ms
constexpr auto sut_cksel_extxosc_8mhz_xx_1kck_14ck_0ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 8.0-    MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_8mhz_xx_16kck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.4-0.9 MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_0mhz4_0mhz9_1kck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.4-0.9 MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 65 ms
constexpr auto sut_cksel_extxosc_0mhz4_0mhz9_16kck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.9-3.0 MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_0mhz9_3mhz_1kck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 0.9-3.0 MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 65 ms
constexpr auto sut_cksel_extxosc_0mhz9_3mhz_16kck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 3.0-8.0 MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_3mhz_8mhz_1kck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 3.0-8.0 MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 65 ms
constexpr auto sut_cksel_extxosc_3mhz_8mhz_16kck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 8.0-    MHz; Start-up time PWRDWN/RESET: 1K CK /14 CK + 4.1 ms
constexpr auto sut_cksel_extxosc_8mhz_xx_1kck_14ck_4ms1 = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Ext. Crystal Osc. 8.0-    MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 65 ms
constexpr auto sut_cksel_extxosc_8mhz_xx_16kck_14ck_65ms = avrcpp::register_field<low_register, 0, 6>{ 0 };

// Clock output on PORTB2
constexpr auto ckout = avrcpp::register_field<low_register, 6, 1>{ 1 };

// Divide clock by 8 internally
constexpr auto ckdiv8 = avrcpp::register_field<low_register, 7, 1>{ 1 };

} // namespace low_fields

constexpr auto low = low_register{};

} // namespace avrcpp::attiny24a::mfuse