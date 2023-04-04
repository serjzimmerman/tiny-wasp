
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

namespace avrcpp::attiny24a::mexint
{

// General Interrupt Flag register
using gifr_register = avrcpp::register_wrapper<0x5a, 1, avrcpp::read_write_flag>;

namespace gifr_fields
{

constexpr auto pcif_0 = avrcpp::register_field<gifr_register, 4, 2>{ 0 };

constexpr auto pcif_1 = avrcpp::register_field<gifr_register, 4, 2>{ 1 };

constexpr auto pcif_2 = avrcpp::register_field<gifr_register, 4, 2>{ 2 };

constexpr auto pcif_3 = avrcpp::register_field<gifr_register, 4, 2>{ 3 };

using pcif = avrcpp::register_field<gifr_register, 4, 2>;

// External Interrupt Flag 0
constexpr auto intf0 = avrcpp::register_field<gifr_register, 6, 1>{ 1 };

} // namespace gifr_fields

constexpr auto gifr = gifr_register{};

// General Interrupt Mask Register
using gimsk_register = avrcpp::register_wrapper<0x5b, 1, avrcpp::read_write_flag>;

namespace gimsk_fields
{

constexpr auto pcie_0 = avrcpp::register_field<gimsk_register, 4, 2>{ 0 };

constexpr auto pcie_1 = avrcpp::register_field<gimsk_register, 4, 2>{ 1 };

constexpr auto pcie_2 = avrcpp::register_field<gimsk_register, 4, 2>{ 2 };

constexpr auto pcie_3 = avrcpp::register_field<gimsk_register, 4, 2>{ 3 };

using pcie = avrcpp::register_field<gimsk_register, 4, 2>;

// External Interrupt Request 0 Enable
constexpr auto int0 = avrcpp::register_field<gimsk_register, 6, 1>{ 1 };

} // namespace gimsk_fields

constexpr auto gimsk = gimsk_register{};

// MCU Control Register
using mcucr_register = avrcpp::register_wrapper<0x55, 1, avrcpp::read_write_flag>;

namespace mcucr_fields
{

// Low Level of INTX
constexpr auto isc0_low_level_of_intx = avrcpp::register_field<mcucr_register, 0, 2>{ 0 };

// Any Logical Change of INTX
constexpr auto isc0_any_logical_change_of_intx = avrcpp::register_field<mcucr_register, 0, 2>{ 1 };

// Falling Edge of INTX
constexpr auto isc0_falling_edge_of_intx = avrcpp::register_field<mcucr_register, 0, 2>{ 2 };

// Rising Edge of INTX
constexpr auto isc0_rising_edge_of_intx = avrcpp::register_field<mcucr_register, 0, 2>{ 3 };

using isc0 = avrcpp::register_field<mcucr_register, 0, 2>;

} // namespace mcucr_fields

constexpr auto mcucr = mcucr_register{};

// Pin Change Enable Mask 0
using pcmsk0_register = avrcpp::register_wrapper<0x32, 1, avrcpp::read_write_flag>;

constexpr auto pcmsk0 = pcmsk0_register{};

// Pin Change Enable Mask 1
using pcmsk1_register = avrcpp::register_wrapper<0x40, 1, avrcpp::read_write_flag>;

constexpr auto pcmsk1 = pcmsk1_register{};

} // namespace avrcpp::attiny24a::mexint