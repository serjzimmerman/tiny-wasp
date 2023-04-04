
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

using adps = avrcpp::register_field<adcsra_register, 0, 3>;

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

using adts = avrcpp::register_field<adcsrb_register, 0, 3>;

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

constexpr auto mux_0 = avrcpp::register_field<admux_register, 0, 6>{ 0 };

constexpr auto mux_1 = avrcpp::register_field<admux_register, 0, 6>{ 1 };

constexpr auto mux_2 = avrcpp::register_field<admux_register, 0, 6>{ 2 };

constexpr auto mux_3 = avrcpp::register_field<admux_register, 0, 6>{ 3 };

constexpr auto mux_4 = avrcpp::register_field<admux_register, 0, 6>{ 4 };

constexpr auto mux_5 = avrcpp::register_field<admux_register, 0, 6>{ 5 };

constexpr auto mux_6 = avrcpp::register_field<admux_register, 0, 6>{ 6 };

constexpr auto mux_7 = avrcpp::register_field<admux_register, 0, 6>{ 7 };

constexpr auto mux_8 = avrcpp::register_field<admux_register, 0, 6>{ 8 };

constexpr auto mux_9 = avrcpp::register_field<admux_register, 0, 6>{ 9 };

constexpr auto mux_10 = avrcpp::register_field<admux_register, 0, 6>{ 10 };

constexpr auto mux_11 = avrcpp::register_field<admux_register, 0, 6>{ 11 };

constexpr auto mux_12 = avrcpp::register_field<admux_register, 0, 6>{ 12 };

constexpr auto mux_13 = avrcpp::register_field<admux_register, 0, 6>{ 13 };

constexpr auto mux_14 = avrcpp::register_field<admux_register, 0, 6>{ 14 };

constexpr auto mux_15 = avrcpp::register_field<admux_register, 0, 6>{ 15 };

constexpr auto mux_16 = avrcpp::register_field<admux_register, 0, 6>{ 16 };

constexpr auto mux_17 = avrcpp::register_field<admux_register, 0, 6>{ 17 };

constexpr auto mux_18 = avrcpp::register_field<admux_register, 0, 6>{ 18 };

constexpr auto mux_19 = avrcpp::register_field<admux_register, 0, 6>{ 19 };

constexpr auto mux_20 = avrcpp::register_field<admux_register, 0, 6>{ 20 };

constexpr auto mux_21 = avrcpp::register_field<admux_register, 0, 6>{ 21 };

constexpr auto mux_22 = avrcpp::register_field<admux_register, 0, 6>{ 22 };

constexpr auto mux_23 = avrcpp::register_field<admux_register, 0, 6>{ 23 };

constexpr auto mux_24 = avrcpp::register_field<admux_register, 0, 6>{ 24 };

constexpr auto mux_25 = avrcpp::register_field<admux_register, 0, 6>{ 25 };

constexpr auto mux_26 = avrcpp::register_field<admux_register, 0, 6>{ 26 };

constexpr auto mux_27 = avrcpp::register_field<admux_register, 0, 6>{ 27 };

constexpr auto mux_28 = avrcpp::register_field<admux_register, 0, 6>{ 28 };

constexpr auto mux_29 = avrcpp::register_field<admux_register, 0, 6>{ 29 };

constexpr auto mux_30 = avrcpp::register_field<admux_register, 0, 6>{ 30 };

constexpr auto mux_31 = avrcpp::register_field<admux_register, 0, 6>{ 31 };

constexpr auto mux_32 = avrcpp::register_field<admux_register, 0, 6>{ 32 };

constexpr auto mux_33 = avrcpp::register_field<admux_register, 0, 6>{ 33 };

constexpr auto mux_34 = avrcpp::register_field<admux_register, 0, 6>{ 34 };

constexpr auto mux_35 = avrcpp::register_field<admux_register, 0, 6>{ 35 };

constexpr auto mux_36 = avrcpp::register_field<admux_register, 0, 6>{ 36 };

constexpr auto mux_37 = avrcpp::register_field<admux_register, 0, 6>{ 37 };

constexpr auto mux_38 = avrcpp::register_field<admux_register, 0, 6>{ 38 };

constexpr auto mux_39 = avrcpp::register_field<admux_register, 0, 6>{ 39 };

constexpr auto mux_40 = avrcpp::register_field<admux_register, 0, 6>{ 40 };

constexpr auto mux_41 = avrcpp::register_field<admux_register, 0, 6>{ 41 };

constexpr auto mux_42 = avrcpp::register_field<admux_register, 0, 6>{ 42 };

constexpr auto mux_43 = avrcpp::register_field<admux_register, 0, 6>{ 43 };

constexpr auto mux_44 = avrcpp::register_field<admux_register, 0, 6>{ 44 };

constexpr auto mux_45 = avrcpp::register_field<admux_register, 0, 6>{ 45 };

constexpr auto mux_46 = avrcpp::register_field<admux_register, 0, 6>{ 46 };

constexpr auto mux_47 = avrcpp::register_field<admux_register, 0, 6>{ 47 };

constexpr auto mux_48 = avrcpp::register_field<admux_register, 0, 6>{ 48 };

constexpr auto mux_49 = avrcpp::register_field<admux_register, 0, 6>{ 49 };

constexpr auto mux_50 = avrcpp::register_field<admux_register, 0, 6>{ 50 };

constexpr auto mux_51 = avrcpp::register_field<admux_register, 0, 6>{ 51 };

constexpr auto mux_52 = avrcpp::register_field<admux_register, 0, 6>{ 52 };

constexpr auto mux_53 = avrcpp::register_field<admux_register, 0, 6>{ 53 };

constexpr auto mux_54 = avrcpp::register_field<admux_register, 0, 6>{ 54 };

constexpr auto mux_55 = avrcpp::register_field<admux_register, 0, 6>{ 55 };

constexpr auto mux_56 = avrcpp::register_field<admux_register, 0, 6>{ 56 };

constexpr auto mux_57 = avrcpp::register_field<admux_register, 0, 6>{ 57 };

constexpr auto mux_58 = avrcpp::register_field<admux_register, 0, 6>{ 58 };

constexpr auto mux_59 = avrcpp::register_field<admux_register, 0, 6>{ 59 };

constexpr auto mux_60 = avrcpp::register_field<admux_register, 0, 6>{ 60 };

constexpr auto mux_61 = avrcpp::register_field<admux_register, 0, 6>{ 61 };

constexpr auto mux_62 = avrcpp::register_field<admux_register, 0, 6>{ 62 };

constexpr auto mux_63 = avrcpp::register_field<admux_register, 0, 6>{ 63 };

using mux = avrcpp::register_field<admux_register, 0, 6>;

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

using refs = avrcpp::register_field<admux_register, 6, 2>;

} // namespace admux_fields

constexpr auto admux = admux_register{};

// Digital Input Disable Register 0
using didr0_register = avrcpp::register_wrapper<0x21, 1, avrcpp::read_write_flag>;

constexpr auto didr0 = didr0_register{};

} // namespace avrcpp::attiny24a::madc