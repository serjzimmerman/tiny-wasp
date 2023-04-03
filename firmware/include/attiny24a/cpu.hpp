
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

namespace avrcpp::attiny24a::mcpu
{

// Clock Prescale Register
using clkpr_register = avrcpp::register_wrapper<0x46, 1, avrcpp::read_write_flag>;

namespace clkpr_fields
{

// 1
constexpr auto clkps_1 = avrcpp::register_field<clkpr_register, 0, 4>{ 0 };

// 2
constexpr auto clkps_2 = avrcpp::register_field<clkpr_register, 0, 4>{ 1 };

// 4
constexpr auto clkps_4 = avrcpp::register_field<clkpr_register, 0, 4>{ 2 };

// 8
constexpr auto clkps_8 = avrcpp::register_field<clkpr_register, 0, 4>{ 3 };

// 16
constexpr auto clkps_16 = avrcpp::register_field<clkpr_register, 0, 4>{ 4 };

// 32
constexpr auto clkps_32 = avrcpp::register_field<clkpr_register, 0, 4>{ 5 };

// 64
constexpr auto clkps_64 = avrcpp::register_field<clkpr_register, 0, 4>{ 6 };

// 128
constexpr auto clkps_128 = avrcpp::register_field<clkpr_register, 0, 4>{ 7 };

// 256
constexpr auto clkps_256 = avrcpp::register_field<clkpr_register, 0, 4>{ 8 };

// Clock Prescaler Change Enable
constexpr auto clkpce = avrcpp::register_field<clkpr_register, 7, 1>{ 1 };

} // namespace clkpr_fields

constexpr auto clkpr = clkpr_register{};

// General Purpose I/O Register 0
using gpior0_register = avrcpp::register_wrapper<0x33, 1, avrcpp::read_write_flag>;

constexpr auto gpior0 = gpior0_register{};

// General Purpose I/O Register 1
using gpior1_register = avrcpp::register_wrapper<0x34, 1, avrcpp::read_write_flag>;

constexpr auto gpior1 = gpior1_register{};

// General Purpose I/O Register 2
using gpior2_register = avrcpp::register_wrapper<0x35, 1, avrcpp::read_write_flag>;

constexpr auto gpior2 = gpior2_register{};

// MCU Control Register
using mcucr_register = avrcpp::register_wrapper<0x55, 1, avrcpp::read_write_flag>;

namespace mcucr_fields
{

// Idle
constexpr auto sm_idle = avrcpp::register_field<mcucr_register, 3, 2>{ 0 };

// ADC Noise Reduction (If Available)
constexpr auto sm_adc = avrcpp::register_field<mcucr_register, 3, 2>{ 1 };

// Power Down
constexpr auto sm_pdown = avrcpp::register_field<mcucr_register, 3, 2>{ 2 };

// Standby
constexpr auto sm_stdby = avrcpp::register_field<mcucr_register, 3, 2>{ 3 };

// Sleep Enable
constexpr auto se = avrcpp::register_field<mcucr_register, 5, 1>{ 1 };

// Pull-up Disable
constexpr auto pud = avrcpp::register_field<mcucr_register, 6, 1>{ 1 };

} // namespace mcucr_fields

constexpr auto mcucr = mcucr_register{};

// MCU Status Register
using mcusr_register = avrcpp::register_wrapper<0x54, 1, avrcpp::read_write_flag>;

namespace mcusr_fields
{

// Power-on reset flag
constexpr auto porf = avrcpp::register_field<mcusr_register, 0, 1>{ 1 };

// External Reset Flag
constexpr auto extrf = avrcpp::register_field<mcusr_register, 1, 1>{ 1 };

// Brown-out Reset Flag
constexpr auto borf = avrcpp::register_field<mcusr_register, 2, 1>{ 1 };

// Watchdog Reset Flag
constexpr auto wdrf = avrcpp::register_field<mcusr_register, 3, 1>{ 1 };

} // namespace mcusr_fields

constexpr auto mcusr = mcusr_register{};

// Oscillator Calibration Value
using osccal_register = avrcpp::register_wrapper<0x51, 1, avrcpp::read_write_flag>;

namespace osccal_fields
{

} // namespace osccal_fields

constexpr auto osccal = osccal_register{};

// Power Reduction Register
using prr_register = avrcpp::register_wrapper<0x20, 1, avrcpp::read_write_flag>;

namespace prr_fields
{

// Power Reduction ADC
constexpr auto pradc = avrcpp::register_field<prr_register, 0, 1>{ 1 };

// Power Reduction USI
constexpr auto prusi = avrcpp::register_field<prr_register, 1, 1>{ 1 };

// Power Reduction Timer/Counter0
constexpr auto prtim0 = avrcpp::register_field<prr_register, 2, 1>{ 1 };

// Power Reduction Timer/Counter1
constexpr auto prtim1 = avrcpp::register_field<prr_register, 3, 1>{ 1 };

} // namespace prr_fields

constexpr auto prr = prr_register{};

// Stack Pointer Low
using spl_register = avrcpp::register_wrapper<0x5d, 1, avrcpp::read_write_flag>;

constexpr auto spl = spl_register{};

} // namespace avrcpp::attiny24a::mcpu