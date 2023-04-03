
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

namespace avrcpp::attiny24a::mboot_load
{

// Store Program Memory Control Register
using spmcsr_register = avrcpp::register_wrapper<0x57, 1, avrcpp::read_write_flag>;

namespace spmcsr_fields
{

// Store Program Memory Enable
constexpr auto spmen = avrcpp::register_field<spmcsr_register, 0, 1>{ 1 };

// Page Erase
constexpr auto pgers = avrcpp::register_field<spmcsr_register, 1, 1>{ 1 };

// Page Write
constexpr auto pgwrt = avrcpp::register_field<spmcsr_register, 2, 1>{ 1 };

// Read fuse and lock bits
constexpr auto rflb = avrcpp::register_field<spmcsr_register, 3, 1>{ 1 };

// Clear temporary page buffer
constexpr auto ctpb = avrcpp::register_field<spmcsr_register, 4, 1>{ 1 };

} // namespace spmcsr_fields

constexpr auto spmcsr = spmcsr_register{};

} // namespace avrcpp::attiny24a::mboot_load