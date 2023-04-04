
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

namespace avrcpp::attiny24a::mac
{

// Analog Comparator Control And Status Register
using acsr_register = avrcpp::register_wrapper<0x28, 1, avrcpp::read_write_flag>;

namespace acsr_fields
{

// Interrupt on Toggle
constexpr auto acis_interrupt_on_toggle = avrcpp::register_field<acsr_register, 0, 2>{ 0 };

// Reserved
constexpr auto acis_reserved = avrcpp::register_field<acsr_register, 0, 2>{ 1 };

// Interrupt on Falling Edge
constexpr auto acis_interrupt_on_falling_edge = avrcpp::register_field<acsr_register, 0, 2>{ 2 };

// Interrupt on Rising Edge
constexpr auto acis_interrupt_on_rising_edge = avrcpp::register_field<acsr_register, 0, 2>{ 3 };

using acis = avrcpp::register_field<acsr_register, 0, 2>;

// Analog Comparator Input Capture Enable
constexpr auto acic = avrcpp::register_field<acsr_register, 2, 1>{ 1 };

// Analog Comparator Interrupt Enable
constexpr auto acie = avrcpp::register_field<acsr_register, 3, 1>{ 1 };

// Analog Comparator Interrupt Flag
constexpr auto aci = avrcpp::register_field<acsr_register, 4, 1>{ 1 };

// Analog Compare Output
constexpr auto aco = avrcpp::register_field<acsr_register, 5, 1>{ 1 };

// Analog Comparator Bandgap Select
constexpr auto acbg = avrcpp::register_field<acsr_register, 6, 1>{ 1 };

// Analog Comparator Disable
constexpr auto acd = avrcpp::register_field<acsr_register, 7, 1>{ 1 };

} // namespace acsr_fields

constexpr auto acsr = acsr_register{};

// ADC Control and Status Register B
using adcsrb_register = avrcpp::register_wrapper<0x23, 1, avrcpp::read_write_flag>;

namespace adcsrb_fields
{

// Analog Comparator Multiplexer Enable
constexpr auto acme = avrcpp::register_field<adcsrb_register, 6, 1>{ 1 };

} // namespace adcsrb_fields

constexpr auto adcsrb = adcsrb_register{};

// No Description.
using didr0_register = avrcpp::register_wrapper<0x21, 1, avrcpp::read_write_flag>;

namespace didr0_fields
{

// ADC 0 Digital input buffer disable
constexpr auto adc0d = avrcpp::register_field<didr0_register, 0, 1>{ 1 };

// ADC 1 Digital input buffer disable
constexpr auto adc1d = avrcpp::register_field<didr0_register, 1, 1>{ 1 };

} // namespace didr0_fields

constexpr auto didr0 = didr0_register{};

} // namespace avrcpp::attiny24a::mac