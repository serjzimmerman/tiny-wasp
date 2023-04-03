
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

namespace avrcpp::attiny24a::mlockbit
{

// No Description.
using lockbit_register = avrcpp::register_wrapper<0x0, 1, avrcpp::read_write_flag>;

namespace lockbit_fields
{

// Further programming and verification disabled
constexpr auto lb_prog_ver_disabled = avrcpp::register_field<lockbit_register, 0, 2>{ 0 };

// Further programming disabled
constexpr auto lb_prog_disabled = avrcpp::register_field<lockbit_register, 0, 2>{ 0 };

// No memory lock features enabled
constexpr auto lb_no_lock = avrcpp::register_field<lockbit_register, 0, 2>{ 0 };

} // namespace lockbit_fields

constexpr auto lockbit = lockbit_register{};

} // namespace avrcpp::attiny24a::mlockbit