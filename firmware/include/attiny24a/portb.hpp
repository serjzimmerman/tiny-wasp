
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

namespace avrcpp::attiny24a::mportb
{

// Data Direction Register, Port B
using ddrb_register = avrcpp::register_wrapper<0x37, 1, avrcpp::read_write_flag>;

namespace ddrb_fields
{

// Pin B0
constexpr auto pb0 = avrcpp::register_field<ddrb_register, 0, 1>{ 1 };

// Pin B1
constexpr auto pb1 = avrcpp::register_field<ddrb_register, 1, 1>{ 1 };

// Pin B2
constexpr auto pb2 = avrcpp::register_field<ddrb_register, 2, 1>{ 1 };

// Pin B3
constexpr auto pb3 = avrcpp::register_field<ddrb_register, 3, 1>{ 1 };

} // namespace ddrb_fields

constexpr auto ddrb = ddrb_register{};

// Input Pins, Port B
using pinb_register = avrcpp::register_wrapper<0x36, 1, avrcpp::read_write_flag>;

namespace pinb_fields
{

// Pin B0
constexpr auto pb0 = avrcpp::register_field<pinb_register, 0, 1>{ 1 };

// Pin B1
constexpr auto pb1 = avrcpp::register_field<pinb_register, 1, 1>{ 1 };

// Pin B2
constexpr auto pb2 = avrcpp::register_field<pinb_register, 2, 1>{ 1 };

// Pin B3
constexpr auto pb3 = avrcpp::register_field<pinb_register, 3, 1>{ 1 };

} // namespace pinb_fields

constexpr auto pinb = pinb_register{};

// Data Register, Port B
using portb_register = avrcpp::register_wrapper<0x38, 1, avrcpp::read_write_flag>;

namespace portb_fields
{

// Pin B0
constexpr auto pb0 = avrcpp::register_field<portb_register, 0, 1>{ 1 };

// Pin B1
constexpr auto pb1 = avrcpp::register_field<portb_register, 1, 1>{ 1 };

// Pin B2
constexpr auto pb2 = avrcpp::register_field<portb_register, 2, 1>{ 1 };

// Pin B3
constexpr auto pb3 = avrcpp::register_field<portb_register, 3, 1>{ 1 };

} // namespace portb_fields

constexpr auto portb = portb_register{};

} // namespace avrcpp::attiny24a::mportb