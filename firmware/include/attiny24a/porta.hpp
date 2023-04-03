
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

namespace avrcpp::attiny24a::mporta
{

// Port A Data Direction Register
using ddra_register = avrcpp::register_wrapper<0x3a, 1, avrcpp::read_write_flag>;

namespace ddra_fields
{

// Pin A0
constexpr auto pa0 = avrcpp::register_field<ddra_register, 0, 1>{ 1 };

// Pin A1
constexpr auto pa1 = avrcpp::register_field<ddra_register, 1, 1>{ 1 };

// Pin A2
constexpr auto pa2 = avrcpp::register_field<ddra_register, 2, 1>{ 1 };

// Pin A3
constexpr auto pa3 = avrcpp::register_field<ddra_register, 3, 1>{ 1 };

// Pin A4
constexpr auto pa4 = avrcpp::register_field<ddra_register, 4, 1>{ 1 };

// Pin A5
constexpr auto pa5 = avrcpp::register_field<ddra_register, 5, 1>{ 1 };

// Pin A6
constexpr auto pa6 = avrcpp::register_field<ddra_register, 6, 1>{ 1 };

// Pin A7
constexpr auto pa7 = avrcpp::register_field<ddra_register, 7, 1>{ 1 };

} // namespace ddra_fields

constexpr auto ddra = ddra_register{};

// Port A Input Pins
using pina_register = avrcpp::register_wrapper<0x39, 1, avrcpp::read_write_flag>;

namespace pina_fields
{

// Pin A0
constexpr auto pa0 = avrcpp::register_field<pina_register, 0, 1>{ 1 };

// Pin A1
constexpr auto pa1 = avrcpp::register_field<pina_register, 1, 1>{ 1 };

// Pin A2
constexpr auto pa2 = avrcpp::register_field<pina_register, 2, 1>{ 1 };

// Pin A3
constexpr auto pa3 = avrcpp::register_field<pina_register, 3, 1>{ 1 };

// Pin A4
constexpr auto pa4 = avrcpp::register_field<pina_register, 4, 1>{ 1 };

// Pin A5
constexpr auto pa5 = avrcpp::register_field<pina_register, 5, 1>{ 1 };

// Pin A6
constexpr auto pa6 = avrcpp::register_field<pina_register, 6, 1>{ 1 };

// Pin A7
constexpr auto pa7 = avrcpp::register_field<pina_register, 7, 1>{ 1 };

} // namespace pina_fields

constexpr auto pina = pina_register{};

// Port A Data Register
using porta_register = avrcpp::register_wrapper<0x3b, 1, avrcpp::read_write_flag>;

namespace porta_fields
{

// Pin A0
constexpr auto pa0 = avrcpp::register_field<porta_register, 0, 1>{ 1 };

// Pin A1
constexpr auto pa1 = avrcpp::register_field<porta_register, 1, 1>{ 1 };

// Pin A2
constexpr auto pa2 = avrcpp::register_field<porta_register, 2, 1>{ 1 };

// Pin A3
constexpr auto pa3 = avrcpp::register_field<porta_register, 3, 1>{ 1 };

// Pin A4
constexpr auto pa4 = avrcpp::register_field<porta_register, 4, 1>{ 1 };

// Pin A5
constexpr auto pa5 = avrcpp::register_field<porta_register, 5, 1>{ 1 };

// Pin A6
constexpr auto pa6 = avrcpp::register_field<porta_register, 6, 1>{ 1 };

// Pin A7
constexpr auto pa7 = avrcpp::register_field<porta_register, 7, 1>{ 1 };

} // namespace porta_fields

constexpr auto porta = porta_register{};

} // namespace avrcpp::attiny24a::mporta