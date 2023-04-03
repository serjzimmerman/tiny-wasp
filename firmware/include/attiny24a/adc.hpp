
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

namespace avrcpp::attiny24a::madc
{

// ADC Data Register  Bytes
using adc_register = avrcpp::register_wrapper<0x24, 2, avrcpp::read_write_flag>;

constexpr auto adc = adc_register{};

// ADC Control and Status Register A
using adcsra_register = avrcpp::register_wrapper<0x26, 1, avrcpp::read_write_flag>;

namespace adcsra_fields
{

// 2
constexpr auto adps_2 = avrcpp::register_field<adcsra_register, 0, 3>{ 1 };

// 4
constexpr auto adps_4 = avrcpp::register_field<adcsra_register, 0, 3>{ 2 };

// 8
constexpr auto adps_8 = avrcpp::register_field<adcsra_register, 0, 3>{ 3 };

// 16
constexpr auto adps_16 = avrcpp::register_field<adcsra_register, 0, 3>{ 4 };

// 32
constexpr auto adps_32 = avrcpp::register_field<adcsra_register, 0, 3>{ 5 };

// 64
constexpr auto adps_64 = avrcpp::register_field<adcsra_register, 0, 3>{ 6 };

// 128
constexpr auto adps_128 = avrcpp::register_field<adcsra_register, 0, 3>{ 7 };

// ADC Interrupt Enable
constexpr auto adie = avrcpp::register_field<adcsra_register, 3, 1>{ 1 };

// ADC Interrupt Flag
constexpr auto adif = avrcpp::register_field<adcsra_register, 4, 1>{ 1 };

// ADC Auto Trigger Enable
constexpr auto adate = avrcpp::register_field<adcsra_register, 5, 1>{ 1 };

// ADC Start Conversion
constexpr auto adsc = avrcpp::register_field<adcsra_register, 6, 1>{ 1 };

// ADC Enable
constexpr auto aden = avrcpp::register_field<adcsra_register, 7, 1>{ 1 };

} // namespace adcsra_fields

constexpr auto adcsra = adcsra_register{};

// ADC Control and Status Register B
using adcsrb_register = avrcpp::register_wrapper<0x23, 1, avrcpp::read_write_flag>;

namespace adcsrb_fields
{

// Free Running mode
constexpr auto adts_free_running_mode = avrcpp::register_field<adcsrb_register, 0, 3>{ 0 };

// Analog Comparator
constexpr auto adts_analog_comparator = avrcpp::register_field<adcsrb_register, 0, 3>{ 1 };

// External Interrupt Request 0
constexpr auto adts_external_interrupt_request_0 = avrcpp::register_field<adcsrb_register, 0, 3>{ 2 };

// Timer/Counter0 Compare Match A
constexpr auto adts_timer_counter0_compare_match_a = avrcpp::register_field<adcsrb_register, 0, 3>{ 3 };

// Timer/Counter0 Overflow
constexpr auto adts_timer_counter0_overflow = avrcpp::register_field<adcsrb_register, 0, 3>{ 4 };

// Timer/Counter1 Compare Match B
constexpr auto adts_timer_counter1_compare_match_b = avrcpp::register_field<adcsrb_register, 0, 3>{ 5 };

// Timer/Counter1 Overflow
constexpr auto adts_timer_counter1_overflow = avrcpp::register_field<adcsrb_register, 0, 3>{ 6 };

// Timer/Counter1 Capture Event
constexpr auto adts_timer_counter1_capture_event = avrcpp::register_field<adcsrb_register, 0, 3>{ 7 };

// ADC Left Adjust Result
constexpr auto adlar = avrcpp::register_field<adcsrb_register, 4, 1>{ 1 };

// Bipolar Input Mode
constexpr auto bin = avrcpp::register_field<adcsrb_register, 7, 1>{ 1 };

} // namespace adcsrb_fields

constexpr auto adcsrb = adcsrb_register{};

// ADC Multiplexer Selection Register
using admux_register = avrcpp::register_wrapper<0x27, 1, avrcpp::read_write_flag>;

namespace admux_fields
{

// VCC used as analog reference, disconnected from PA0 (AREF)
constexpr auto refs_vcc_used_as_analog_reference_disconnected_from_pa0_aref =
    avrcpp::register_field<admux_register, 6, 2>{ 0 };

// External voltage reference at PA0 (AREF) pin, internal reference turned off
constexpr auto refs_external_voltage_reference_at_pa0_aref_pin_internal_reference_turned_off =
    avrcpp::register_field<admux_register, 6, 2>{ 1 };

// Internal 1.1V voltage reference
constexpr auto refs_internal_1_1v_voltage_reference = avrcpp::register_field<admux_register, 6, 2>{ 2 };

// Reserved
constexpr auto refs_reserved = avrcpp::register_field<admux_register, 6, 2>{ 3 };

} // namespace admux_fields

constexpr auto admux = admux_register{};

// Digital Input Disable Register 0
using didr0_register = avrcpp::register_wrapper<0x21, 1, avrcpp::read_write_flag>;

constexpr auto didr0 = didr0_register{};

} // namespace avrcpp::attiny24a::madc