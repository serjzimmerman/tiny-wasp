
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

using clkps = avrcpp::register_field<clkpr_register, 0, 4>;

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

using sm = avrcpp::register_field<mcucr_register, 3, 2>;

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

constexpr auto osccal_0 = avrcpp::register_field<osccal_register, 0, 8>{ 0 };

constexpr auto osccal_1 = avrcpp::register_field<osccal_register, 0, 8>{ 1 };

constexpr auto osccal_2 = avrcpp::register_field<osccal_register, 0, 8>{ 2 };

constexpr auto osccal_3 = avrcpp::register_field<osccal_register, 0, 8>{ 3 };

constexpr auto osccal_4 = avrcpp::register_field<osccal_register, 0, 8>{ 4 };

constexpr auto osccal_5 = avrcpp::register_field<osccal_register, 0, 8>{ 5 };

constexpr auto osccal_6 = avrcpp::register_field<osccal_register, 0, 8>{ 6 };

constexpr auto osccal_7 = avrcpp::register_field<osccal_register, 0, 8>{ 7 };

constexpr auto osccal_8 = avrcpp::register_field<osccal_register, 0, 8>{ 8 };

constexpr auto osccal_9 = avrcpp::register_field<osccal_register, 0, 8>{ 9 };

constexpr auto osccal_10 = avrcpp::register_field<osccal_register, 0, 8>{ 10 };

constexpr auto osccal_11 = avrcpp::register_field<osccal_register, 0, 8>{ 11 };

constexpr auto osccal_12 = avrcpp::register_field<osccal_register, 0, 8>{ 12 };

constexpr auto osccal_13 = avrcpp::register_field<osccal_register, 0, 8>{ 13 };

constexpr auto osccal_14 = avrcpp::register_field<osccal_register, 0, 8>{ 14 };

constexpr auto osccal_15 = avrcpp::register_field<osccal_register, 0, 8>{ 15 };

constexpr auto osccal_16 = avrcpp::register_field<osccal_register, 0, 8>{ 16 };

constexpr auto osccal_17 = avrcpp::register_field<osccal_register, 0, 8>{ 17 };

constexpr auto osccal_18 = avrcpp::register_field<osccal_register, 0, 8>{ 18 };

constexpr auto osccal_19 = avrcpp::register_field<osccal_register, 0, 8>{ 19 };

constexpr auto osccal_20 = avrcpp::register_field<osccal_register, 0, 8>{ 20 };

constexpr auto osccal_21 = avrcpp::register_field<osccal_register, 0, 8>{ 21 };

constexpr auto osccal_22 = avrcpp::register_field<osccal_register, 0, 8>{ 22 };

constexpr auto osccal_23 = avrcpp::register_field<osccal_register, 0, 8>{ 23 };

constexpr auto osccal_24 = avrcpp::register_field<osccal_register, 0, 8>{ 24 };

constexpr auto osccal_25 = avrcpp::register_field<osccal_register, 0, 8>{ 25 };

constexpr auto osccal_26 = avrcpp::register_field<osccal_register, 0, 8>{ 26 };

constexpr auto osccal_27 = avrcpp::register_field<osccal_register, 0, 8>{ 27 };

constexpr auto osccal_28 = avrcpp::register_field<osccal_register, 0, 8>{ 28 };

constexpr auto osccal_29 = avrcpp::register_field<osccal_register, 0, 8>{ 29 };

constexpr auto osccal_30 = avrcpp::register_field<osccal_register, 0, 8>{ 30 };

constexpr auto osccal_31 = avrcpp::register_field<osccal_register, 0, 8>{ 31 };

constexpr auto osccal_32 = avrcpp::register_field<osccal_register, 0, 8>{ 32 };

constexpr auto osccal_33 = avrcpp::register_field<osccal_register, 0, 8>{ 33 };

constexpr auto osccal_34 = avrcpp::register_field<osccal_register, 0, 8>{ 34 };

constexpr auto osccal_35 = avrcpp::register_field<osccal_register, 0, 8>{ 35 };

constexpr auto osccal_36 = avrcpp::register_field<osccal_register, 0, 8>{ 36 };

constexpr auto osccal_37 = avrcpp::register_field<osccal_register, 0, 8>{ 37 };

constexpr auto osccal_38 = avrcpp::register_field<osccal_register, 0, 8>{ 38 };

constexpr auto osccal_39 = avrcpp::register_field<osccal_register, 0, 8>{ 39 };

constexpr auto osccal_40 = avrcpp::register_field<osccal_register, 0, 8>{ 40 };

constexpr auto osccal_41 = avrcpp::register_field<osccal_register, 0, 8>{ 41 };

constexpr auto osccal_42 = avrcpp::register_field<osccal_register, 0, 8>{ 42 };

constexpr auto osccal_43 = avrcpp::register_field<osccal_register, 0, 8>{ 43 };

constexpr auto osccal_44 = avrcpp::register_field<osccal_register, 0, 8>{ 44 };

constexpr auto osccal_45 = avrcpp::register_field<osccal_register, 0, 8>{ 45 };

constexpr auto osccal_46 = avrcpp::register_field<osccal_register, 0, 8>{ 46 };

constexpr auto osccal_47 = avrcpp::register_field<osccal_register, 0, 8>{ 47 };

constexpr auto osccal_48 = avrcpp::register_field<osccal_register, 0, 8>{ 48 };

constexpr auto osccal_49 = avrcpp::register_field<osccal_register, 0, 8>{ 49 };

constexpr auto osccal_50 = avrcpp::register_field<osccal_register, 0, 8>{ 50 };

constexpr auto osccal_51 = avrcpp::register_field<osccal_register, 0, 8>{ 51 };

constexpr auto osccal_52 = avrcpp::register_field<osccal_register, 0, 8>{ 52 };

constexpr auto osccal_53 = avrcpp::register_field<osccal_register, 0, 8>{ 53 };

constexpr auto osccal_54 = avrcpp::register_field<osccal_register, 0, 8>{ 54 };

constexpr auto osccal_55 = avrcpp::register_field<osccal_register, 0, 8>{ 55 };

constexpr auto osccal_56 = avrcpp::register_field<osccal_register, 0, 8>{ 56 };

constexpr auto osccal_57 = avrcpp::register_field<osccal_register, 0, 8>{ 57 };

constexpr auto osccal_58 = avrcpp::register_field<osccal_register, 0, 8>{ 58 };

constexpr auto osccal_59 = avrcpp::register_field<osccal_register, 0, 8>{ 59 };

constexpr auto osccal_60 = avrcpp::register_field<osccal_register, 0, 8>{ 60 };

constexpr auto osccal_61 = avrcpp::register_field<osccal_register, 0, 8>{ 61 };

constexpr auto osccal_62 = avrcpp::register_field<osccal_register, 0, 8>{ 62 };

constexpr auto osccal_63 = avrcpp::register_field<osccal_register, 0, 8>{ 63 };

constexpr auto osccal_64 = avrcpp::register_field<osccal_register, 0, 8>{ 64 };

constexpr auto osccal_65 = avrcpp::register_field<osccal_register, 0, 8>{ 65 };

constexpr auto osccal_66 = avrcpp::register_field<osccal_register, 0, 8>{ 66 };

constexpr auto osccal_67 = avrcpp::register_field<osccal_register, 0, 8>{ 67 };

constexpr auto osccal_68 = avrcpp::register_field<osccal_register, 0, 8>{ 68 };

constexpr auto osccal_69 = avrcpp::register_field<osccal_register, 0, 8>{ 69 };

constexpr auto osccal_70 = avrcpp::register_field<osccal_register, 0, 8>{ 70 };

constexpr auto osccal_71 = avrcpp::register_field<osccal_register, 0, 8>{ 71 };

constexpr auto osccal_72 = avrcpp::register_field<osccal_register, 0, 8>{ 72 };

constexpr auto osccal_73 = avrcpp::register_field<osccal_register, 0, 8>{ 73 };

constexpr auto osccal_74 = avrcpp::register_field<osccal_register, 0, 8>{ 74 };

constexpr auto osccal_75 = avrcpp::register_field<osccal_register, 0, 8>{ 75 };

constexpr auto osccal_76 = avrcpp::register_field<osccal_register, 0, 8>{ 76 };

constexpr auto osccal_77 = avrcpp::register_field<osccal_register, 0, 8>{ 77 };

constexpr auto osccal_78 = avrcpp::register_field<osccal_register, 0, 8>{ 78 };

constexpr auto osccal_79 = avrcpp::register_field<osccal_register, 0, 8>{ 79 };

constexpr auto osccal_80 = avrcpp::register_field<osccal_register, 0, 8>{ 80 };

constexpr auto osccal_81 = avrcpp::register_field<osccal_register, 0, 8>{ 81 };

constexpr auto osccal_82 = avrcpp::register_field<osccal_register, 0, 8>{ 82 };

constexpr auto osccal_83 = avrcpp::register_field<osccal_register, 0, 8>{ 83 };

constexpr auto osccal_84 = avrcpp::register_field<osccal_register, 0, 8>{ 84 };

constexpr auto osccal_85 = avrcpp::register_field<osccal_register, 0, 8>{ 85 };

constexpr auto osccal_86 = avrcpp::register_field<osccal_register, 0, 8>{ 86 };

constexpr auto osccal_87 = avrcpp::register_field<osccal_register, 0, 8>{ 87 };

constexpr auto osccal_88 = avrcpp::register_field<osccal_register, 0, 8>{ 88 };

constexpr auto osccal_89 = avrcpp::register_field<osccal_register, 0, 8>{ 89 };

constexpr auto osccal_90 = avrcpp::register_field<osccal_register, 0, 8>{ 90 };

constexpr auto osccal_91 = avrcpp::register_field<osccal_register, 0, 8>{ 91 };

constexpr auto osccal_92 = avrcpp::register_field<osccal_register, 0, 8>{ 92 };

constexpr auto osccal_93 = avrcpp::register_field<osccal_register, 0, 8>{ 93 };

constexpr auto osccal_94 = avrcpp::register_field<osccal_register, 0, 8>{ 94 };

constexpr auto osccal_95 = avrcpp::register_field<osccal_register, 0, 8>{ 95 };

constexpr auto osccal_96 = avrcpp::register_field<osccal_register, 0, 8>{ 96 };

constexpr auto osccal_97 = avrcpp::register_field<osccal_register, 0, 8>{ 97 };

constexpr auto osccal_98 = avrcpp::register_field<osccal_register, 0, 8>{ 98 };

constexpr auto osccal_99 = avrcpp::register_field<osccal_register, 0, 8>{ 99 };

constexpr auto osccal_100 = avrcpp::register_field<osccal_register, 0, 8>{ 100 };

constexpr auto osccal_101 = avrcpp::register_field<osccal_register, 0, 8>{ 101 };

constexpr auto osccal_102 = avrcpp::register_field<osccal_register, 0, 8>{ 102 };

constexpr auto osccal_103 = avrcpp::register_field<osccal_register, 0, 8>{ 103 };

constexpr auto osccal_104 = avrcpp::register_field<osccal_register, 0, 8>{ 104 };

constexpr auto osccal_105 = avrcpp::register_field<osccal_register, 0, 8>{ 105 };

constexpr auto osccal_106 = avrcpp::register_field<osccal_register, 0, 8>{ 106 };

constexpr auto osccal_107 = avrcpp::register_field<osccal_register, 0, 8>{ 107 };

constexpr auto osccal_108 = avrcpp::register_field<osccal_register, 0, 8>{ 108 };

constexpr auto osccal_109 = avrcpp::register_field<osccal_register, 0, 8>{ 109 };

constexpr auto osccal_110 = avrcpp::register_field<osccal_register, 0, 8>{ 110 };

constexpr auto osccal_111 = avrcpp::register_field<osccal_register, 0, 8>{ 111 };

constexpr auto osccal_112 = avrcpp::register_field<osccal_register, 0, 8>{ 112 };

constexpr auto osccal_113 = avrcpp::register_field<osccal_register, 0, 8>{ 113 };

constexpr auto osccal_114 = avrcpp::register_field<osccal_register, 0, 8>{ 114 };

constexpr auto osccal_115 = avrcpp::register_field<osccal_register, 0, 8>{ 115 };

constexpr auto osccal_116 = avrcpp::register_field<osccal_register, 0, 8>{ 116 };

constexpr auto osccal_117 = avrcpp::register_field<osccal_register, 0, 8>{ 117 };

constexpr auto osccal_118 = avrcpp::register_field<osccal_register, 0, 8>{ 118 };

constexpr auto osccal_119 = avrcpp::register_field<osccal_register, 0, 8>{ 119 };

constexpr auto osccal_120 = avrcpp::register_field<osccal_register, 0, 8>{ 120 };

constexpr auto osccal_121 = avrcpp::register_field<osccal_register, 0, 8>{ 121 };

constexpr auto osccal_122 = avrcpp::register_field<osccal_register, 0, 8>{ 122 };

constexpr auto osccal_123 = avrcpp::register_field<osccal_register, 0, 8>{ 123 };

constexpr auto osccal_124 = avrcpp::register_field<osccal_register, 0, 8>{ 124 };

constexpr auto osccal_125 = avrcpp::register_field<osccal_register, 0, 8>{ 125 };

constexpr auto osccal_126 = avrcpp::register_field<osccal_register, 0, 8>{ 126 };

constexpr auto osccal_127 = avrcpp::register_field<osccal_register, 0, 8>{ 127 };

constexpr auto osccal_128 = avrcpp::register_field<osccal_register, 0, 8>{ 128 };

constexpr auto osccal_129 = avrcpp::register_field<osccal_register, 0, 8>{ 129 };

constexpr auto osccal_130 = avrcpp::register_field<osccal_register, 0, 8>{ 130 };

constexpr auto osccal_131 = avrcpp::register_field<osccal_register, 0, 8>{ 131 };

constexpr auto osccal_132 = avrcpp::register_field<osccal_register, 0, 8>{ 132 };

constexpr auto osccal_133 = avrcpp::register_field<osccal_register, 0, 8>{ 133 };

constexpr auto osccal_134 = avrcpp::register_field<osccal_register, 0, 8>{ 134 };

constexpr auto osccal_135 = avrcpp::register_field<osccal_register, 0, 8>{ 135 };

constexpr auto osccal_136 = avrcpp::register_field<osccal_register, 0, 8>{ 136 };

constexpr auto osccal_137 = avrcpp::register_field<osccal_register, 0, 8>{ 137 };

constexpr auto osccal_138 = avrcpp::register_field<osccal_register, 0, 8>{ 138 };

constexpr auto osccal_139 = avrcpp::register_field<osccal_register, 0, 8>{ 139 };

constexpr auto osccal_140 = avrcpp::register_field<osccal_register, 0, 8>{ 140 };

constexpr auto osccal_141 = avrcpp::register_field<osccal_register, 0, 8>{ 141 };

constexpr auto osccal_142 = avrcpp::register_field<osccal_register, 0, 8>{ 142 };

constexpr auto osccal_143 = avrcpp::register_field<osccal_register, 0, 8>{ 143 };

constexpr auto osccal_144 = avrcpp::register_field<osccal_register, 0, 8>{ 144 };

constexpr auto osccal_145 = avrcpp::register_field<osccal_register, 0, 8>{ 145 };

constexpr auto osccal_146 = avrcpp::register_field<osccal_register, 0, 8>{ 146 };

constexpr auto osccal_147 = avrcpp::register_field<osccal_register, 0, 8>{ 147 };

constexpr auto osccal_148 = avrcpp::register_field<osccal_register, 0, 8>{ 148 };

constexpr auto osccal_149 = avrcpp::register_field<osccal_register, 0, 8>{ 149 };

constexpr auto osccal_150 = avrcpp::register_field<osccal_register, 0, 8>{ 150 };

constexpr auto osccal_151 = avrcpp::register_field<osccal_register, 0, 8>{ 151 };

constexpr auto osccal_152 = avrcpp::register_field<osccal_register, 0, 8>{ 152 };

constexpr auto osccal_153 = avrcpp::register_field<osccal_register, 0, 8>{ 153 };

constexpr auto osccal_154 = avrcpp::register_field<osccal_register, 0, 8>{ 154 };

constexpr auto osccal_155 = avrcpp::register_field<osccal_register, 0, 8>{ 155 };

constexpr auto osccal_156 = avrcpp::register_field<osccal_register, 0, 8>{ 156 };

constexpr auto osccal_157 = avrcpp::register_field<osccal_register, 0, 8>{ 157 };

constexpr auto osccal_158 = avrcpp::register_field<osccal_register, 0, 8>{ 158 };

constexpr auto osccal_159 = avrcpp::register_field<osccal_register, 0, 8>{ 159 };

constexpr auto osccal_160 = avrcpp::register_field<osccal_register, 0, 8>{ 160 };

constexpr auto osccal_161 = avrcpp::register_field<osccal_register, 0, 8>{ 161 };

constexpr auto osccal_162 = avrcpp::register_field<osccal_register, 0, 8>{ 162 };

constexpr auto osccal_163 = avrcpp::register_field<osccal_register, 0, 8>{ 163 };

constexpr auto osccal_164 = avrcpp::register_field<osccal_register, 0, 8>{ 164 };

constexpr auto osccal_165 = avrcpp::register_field<osccal_register, 0, 8>{ 165 };

constexpr auto osccal_166 = avrcpp::register_field<osccal_register, 0, 8>{ 166 };

constexpr auto osccal_167 = avrcpp::register_field<osccal_register, 0, 8>{ 167 };

constexpr auto osccal_168 = avrcpp::register_field<osccal_register, 0, 8>{ 168 };

constexpr auto osccal_169 = avrcpp::register_field<osccal_register, 0, 8>{ 169 };

constexpr auto osccal_170 = avrcpp::register_field<osccal_register, 0, 8>{ 170 };

constexpr auto osccal_171 = avrcpp::register_field<osccal_register, 0, 8>{ 171 };

constexpr auto osccal_172 = avrcpp::register_field<osccal_register, 0, 8>{ 172 };

constexpr auto osccal_173 = avrcpp::register_field<osccal_register, 0, 8>{ 173 };

constexpr auto osccal_174 = avrcpp::register_field<osccal_register, 0, 8>{ 174 };

constexpr auto osccal_175 = avrcpp::register_field<osccal_register, 0, 8>{ 175 };

constexpr auto osccal_176 = avrcpp::register_field<osccal_register, 0, 8>{ 176 };

constexpr auto osccal_177 = avrcpp::register_field<osccal_register, 0, 8>{ 177 };

constexpr auto osccal_178 = avrcpp::register_field<osccal_register, 0, 8>{ 178 };

constexpr auto osccal_179 = avrcpp::register_field<osccal_register, 0, 8>{ 179 };

constexpr auto osccal_180 = avrcpp::register_field<osccal_register, 0, 8>{ 180 };

constexpr auto osccal_181 = avrcpp::register_field<osccal_register, 0, 8>{ 181 };

constexpr auto osccal_182 = avrcpp::register_field<osccal_register, 0, 8>{ 182 };

constexpr auto osccal_183 = avrcpp::register_field<osccal_register, 0, 8>{ 183 };

constexpr auto osccal_184 = avrcpp::register_field<osccal_register, 0, 8>{ 184 };

constexpr auto osccal_185 = avrcpp::register_field<osccal_register, 0, 8>{ 185 };

constexpr auto osccal_186 = avrcpp::register_field<osccal_register, 0, 8>{ 186 };

constexpr auto osccal_187 = avrcpp::register_field<osccal_register, 0, 8>{ 187 };

constexpr auto osccal_188 = avrcpp::register_field<osccal_register, 0, 8>{ 188 };

constexpr auto osccal_189 = avrcpp::register_field<osccal_register, 0, 8>{ 189 };

constexpr auto osccal_190 = avrcpp::register_field<osccal_register, 0, 8>{ 190 };

constexpr auto osccal_191 = avrcpp::register_field<osccal_register, 0, 8>{ 191 };

constexpr auto osccal_192 = avrcpp::register_field<osccal_register, 0, 8>{ 192 };

constexpr auto osccal_193 = avrcpp::register_field<osccal_register, 0, 8>{ 193 };

constexpr auto osccal_194 = avrcpp::register_field<osccal_register, 0, 8>{ 194 };

constexpr auto osccal_195 = avrcpp::register_field<osccal_register, 0, 8>{ 195 };

constexpr auto osccal_196 = avrcpp::register_field<osccal_register, 0, 8>{ 196 };

constexpr auto osccal_197 = avrcpp::register_field<osccal_register, 0, 8>{ 197 };

constexpr auto osccal_198 = avrcpp::register_field<osccal_register, 0, 8>{ 198 };

constexpr auto osccal_199 = avrcpp::register_field<osccal_register, 0, 8>{ 199 };

constexpr auto osccal_200 = avrcpp::register_field<osccal_register, 0, 8>{ 200 };

constexpr auto osccal_201 = avrcpp::register_field<osccal_register, 0, 8>{ 201 };

constexpr auto osccal_202 = avrcpp::register_field<osccal_register, 0, 8>{ 202 };

constexpr auto osccal_203 = avrcpp::register_field<osccal_register, 0, 8>{ 203 };

constexpr auto osccal_204 = avrcpp::register_field<osccal_register, 0, 8>{ 204 };

constexpr auto osccal_205 = avrcpp::register_field<osccal_register, 0, 8>{ 205 };

constexpr auto osccal_206 = avrcpp::register_field<osccal_register, 0, 8>{ 206 };

constexpr auto osccal_207 = avrcpp::register_field<osccal_register, 0, 8>{ 207 };

constexpr auto osccal_208 = avrcpp::register_field<osccal_register, 0, 8>{ 208 };

constexpr auto osccal_209 = avrcpp::register_field<osccal_register, 0, 8>{ 209 };

constexpr auto osccal_210 = avrcpp::register_field<osccal_register, 0, 8>{ 210 };

constexpr auto osccal_211 = avrcpp::register_field<osccal_register, 0, 8>{ 211 };

constexpr auto osccal_212 = avrcpp::register_field<osccal_register, 0, 8>{ 212 };

constexpr auto osccal_213 = avrcpp::register_field<osccal_register, 0, 8>{ 213 };

constexpr auto osccal_214 = avrcpp::register_field<osccal_register, 0, 8>{ 214 };

constexpr auto osccal_215 = avrcpp::register_field<osccal_register, 0, 8>{ 215 };

constexpr auto osccal_216 = avrcpp::register_field<osccal_register, 0, 8>{ 216 };

constexpr auto osccal_217 = avrcpp::register_field<osccal_register, 0, 8>{ 217 };

constexpr auto osccal_218 = avrcpp::register_field<osccal_register, 0, 8>{ 218 };

constexpr auto osccal_219 = avrcpp::register_field<osccal_register, 0, 8>{ 219 };

constexpr auto osccal_220 = avrcpp::register_field<osccal_register, 0, 8>{ 220 };

constexpr auto osccal_221 = avrcpp::register_field<osccal_register, 0, 8>{ 221 };

constexpr auto osccal_222 = avrcpp::register_field<osccal_register, 0, 8>{ 222 };

constexpr auto osccal_223 = avrcpp::register_field<osccal_register, 0, 8>{ 223 };

constexpr auto osccal_224 = avrcpp::register_field<osccal_register, 0, 8>{ 224 };

constexpr auto osccal_225 = avrcpp::register_field<osccal_register, 0, 8>{ 225 };

constexpr auto osccal_226 = avrcpp::register_field<osccal_register, 0, 8>{ 226 };

constexpr auto osccal_227 = avrcpp::register_field<osccal_register, 0, 8>{ 227 };

constexpr auto osccal_228 = avrcpp::register_field<osccal_register, 0, 8>{ 228 };

constexpr auto osccal_229 = avrcpp::register_field<osccal_register, 0, 8>{ 229 };

constexpr auto osccal_230 = avrcpp::register_field<osccal_register, 0, 8>{ 230 };

constexpr auto osccal_231 = avrcpp::register_field<osccal_register, 0, 8>{ 231 };

constexpr auto osccal_232 = avrcpp::register_field<osccal_register, 0, 8>{ 232 };

constexpr auto osccal_233 = avrcpp::register_field<osccal_register, 0, 8>{ 233 };

constexpr auto osccal_234 = avrcpp::register_field<osccal_register, 0, 8>{ 234 };

constexpr auto osccal_235 = avrcpp::register_field<osccal_register, 0, 8>{ 235 };

constexpr auto osccal_236 = avrcpp::register_field<osccal_register, 0, 8>{ 236 };

constexpr auto osccal_237 = avrcpp::register_field<osccal_register, 0, 8>{ 237 };

constexpr auto osccal_238 = avrcpp::register_field<osccal_register, 0, 8>{ 238 };

constexpr auto osccal_239 = avrcpp::register_field<osccal_register, 0, 8>{ 239 };

constexpr auto osccal_240 = avrcpp::register_field<osccal_register, 0, 8>{ 240 };

constexpr auto osccal_241 = avrcpp::register_field<osccal_register, 0, 8>{ 241 };

constexpr auto osccal_242 = avrcpp::register_field<osccal_register, 0, 8>{ 242 };

constexpr auto osccal_243 = avrcpp::register_field<osccal_register, 0, 8>{ 243 };

constexpr auto osccal_244 = avrcpp::register_field<osccal_register, 0, 8>{ 244 };

constexpr auto osccal_245 = avrcpp::register_field<osccal_register, 0, 8>{ 245 };

constexpr auto osccal_246 = avrcpp::register_field<osccal_register, 0, 8>{ 246 };

constexpr auto osccal_247 = avrcpp::register_field<osccal_register, 0, 8>{ 247 };

constexpr auto osccal_248 = avrcpp::register_field<osccal_register, 0, 8>{ 248 };

constexpr auto osccal_249 = avrcpp::register_field<osccal_register, 0, 8>{ 249 };

constexpr auto osccal_250 = avrcpp::register_field<osccal_register, 0, 8>{ 250 };

constexpr auto osccal_251 = avrcpp::register_field<osccal_register, 0, 8>{ 251 };

constexpr auto osccal_252 = avrcpp::register_field<osccal_register, 0, 8>{ 252 };

constexpr auto osccal_253 = avrcpp::register_field<osccal_register, 0, 8>{ 253 };

constexpr auto osccal_254 = avrcpp::register_field<osccal_register, 0, 8>{ 254 };

constexpr auto osccal_255 = avrcpp::register_field<osccal_register, 0, 8>{ 255 };

using osccal = avrcpp::register_field<osccal_register, 0, 8>;

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