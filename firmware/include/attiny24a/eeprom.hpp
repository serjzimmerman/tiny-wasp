
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

namespace avrcpp::attiny24a::meeprom
{

// EEPROM Address Register  Bytes
using eear_register = avrcpp::register_wrapper<0x3e, 2, avrcpp::read_write_flag>;

constexpr auto eear = eear_register{};

// EEPROM Control Register
using eecr_register = avrcpp::register_wrapper<0x3c, 1, avrcpp::read_write_flag>;

namespace eecr_fields
{

// EEPROM Read Enable
constexpr auto eere = avrcpp::register_field<eecr_register, 0, 1>{ 1 };

// EEPROM Write Enable
constexpr auto eepe = avrcpp::register_field<eecr_register, 1, 1>{ 1 };

// EEPROM Master Write Enable
constexpr auto eempe = avrcpp::register_field<eecr_register, 2, 1>{ 1 };

// EEPROM Ready Interrupt Enable
constexpr auto eerie = avrcpp::register_field<eecr_register, 3, 1>{ 1 };

// Erase and Write in one operation
constexpr auto eepm_erase_and_write_in_one_operation = avrcpp::register_field<eecr_register, 4, 2>{ 0 };

// Erase Only
constexpr auto eepm_erase_only = avrcpp::register_field<eecr_register, 4, 2>{ 1 };

// Write Only
constexpr auto eepm_write_only = avrcpp::register_field<eecr_register, 4, 2>{ 2 };

using eepm = avrcpp::register_field<eecr_register, 4, 2>;

} // namespace eecr_fields

constexpr auto eecr = eecr_register{};

// EEPROM Data Register
using eedr_register = avrcpp::register_wrapper<0x3d, 1, avrcpp::read_write_flag>;

constexpr auto eedr = eedr_register{};

} // namespace avrcpp::attiny24a::meeprom