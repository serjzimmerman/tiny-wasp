
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

namespace avrcpp::attiny24a::mwdt
{

// Watchdog Timer Control Register
using wdtcsr_register = avrcpp::register_wrapper<0x41, 1, avrcpp::read_write_flag>;

namespace wdtcsr_fields
{

// Oscillator Cycles 2K
constexpr auto wdp_oscillator_cycles_2k = avrcpp::register_field<wdtcsr_register, 0, 6>{ 0 };

// Oscillator Cycles 4K
constexpr auto wdp_oscillator_cycles_4k = avrcpp::register_field<wdtcsr_register, 0, 6>{ 1 };

// Oscillator Cycles 8K
constexpr auto wdp_oscillator_cycles_8k = avrcpp::register_field<wdtcsr_register, 0, 6>{ 2 };

// Oscillator Cycles 16K
constexpr auto wdp_oscillator_cycles_16k = avrcpp::register_field<wdtcsr_register, 0, 6>{ 3 };

// Oscillator Cycles 32K
constexpr auto wdp_oscillator_cycles_32k = avrcpp::register_field<wdtcsr_register, 0, 6>{ 4 };

// Oscillator Cycles 64K
constexpr auto wdp_oscillator_cycles_64k = avrcpp::register_field<wdtcsr_register, 0, 6>{ 5 };

// Oscillator Cycles 128K
constexpr auto wdp_oscillator_cycles_128k = avrcpp::register_field<wdtcsr_register, 0, 6>{ 6 };

// Oscillator Cycles 256K
constexpr auto wdp_oscillator_cycles_256k = avrcpp::register_field<wdtcsr_register, 0, 6>{ 7 };

using wdp = avrcpp::register_field<wdtcsr_register, 0, 6>;

// Watch Dog Enable
constexpr auto wde = avrcpp::register_field<wdtcsr_register, 3, 1>{ 1 };

// Watchdog Change Enable
constexpr auto wdce = avrcpp::register_field<wdtcsr_register, 4, 1>{ 1 };

// Watchdog Timeout Interrupt Enable
constexpr auto wdie = avrcpp::register_field<wdtcsr_register, 6, 1>{ 1 };

// Watchdog Timeout Interrupt Flag
constexpr auto wdif = avrcpp::register_field<wdtcsr_register, 7, 1>{ 1 };

} // namespace wdtcsr_fields

constexpr auto wdtcsr = wdtcsr_register{};

} // namespace avrcpp::attiny24a::mwdt