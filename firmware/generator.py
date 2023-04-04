#
# Copyright 2022 Sergei Zimmerman <serjtsimmerman@gmail.com>
# Copyright 2015 Paul Osborne <osbpau@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

from cmsis_svd.parser import SVDParser
from pathlib import Path

svd_path = Path("info/ATtiny24A.svd")
output_dir_path = Path("include/attiny24a")
output_dir_path.mkdir(0o755, True, True)

header_start = \
    '''
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

'''


def in_namespace(namespace: str, content: str):
    return \
        '''namespace {0}
{{

{1}

}} // namespace {0}'''.format(namespace, content)


def generate_field(field):
    description = field.description

    reg = field.parent
    result = ''

    if not field.is_enumerated_type and field.bit_width == 1:
        definition = 'constexpr auto {} = avrcpp::register_field<{}_register, {}, {}>{{1}};'.format(
            field.name.lower(), reg.name.lower(), field.bit_offset, field.bit_width)
        result = '// {}\n{}\n'.format(description, definition)
    elif field.enumerated_values is not None and len(field.enumerated_values) != 0:
        for enum in field.enumerated_values:
            result += '// {}\nconstexpr auto {}_{} = avrcpp::register_field<{}_register, {}, {}>{{{}}};\n\n'.format(
                enum.description, field.name.lower(), enum.name.lower(), reg.name.lower(), field.bit_offset, field.bit_width, enum.value)
        result += 'using {} = avrcpp::register_field<{}_register, {}, {}>;\n\n'.format(
            field.name.lower(), reg.name.lower(), field.bit_offset, field.bit_width)
    else:
        for i in range(0, int(2 ** field.bit_width)):
            result += 'constexpr auto {}_{:d} = avrcpp::register_field<{}_register, {}, {}>{{{}}};\n\n'.format(
                field.name.lower(), i, reg.name.lower(), field.bit_offset, field.bit_width, i)
        result += 'using {} = avrcpp::register_field<{}_register, {}, {}>;\n\n'.format(
            field.name.lower(), reg.name.lower(), field.bit_offset, field.bit_width)
    return result


def generate_register(base_address, reg):
    description = reg.description

    access_map = {'read-write': 'avrcpp::read_write_flag',
                  'read': 'avrcpp::read_only_flag', 'write': 'avrcpp::write_only_flag'}

    access = access_map[reg.access]

    byte_count = reg.size // 8

    if reg.size % 8 != 0:
        raise ValueError(
            'Register size is not an even number of bytes({})'.format(reg.size))

    fields = ''
    for field in reg.fields:
        if field.is_reserved:
            continue
        print('{}:{}'.format(reg.name, field.name))
        fields += '{}\n'.format(generate_field(field))

    definition = 'using {}_register = avrcpp::register_wrapper<0x{:x}, {:d}, {}>;\n'.format(
        reg.name.lower(), base_address + reg.address_offset, byte_count, access, fields)

    fields = in_namespace('{}_fields'.format(reg.name.lower()), fields)
    if len(reg.fields) == 0:
        fields = ''

    variable = ('constexpr auto {0} = {0}_register{{}};\n').format(
        reg.name.lower())

    result = '// {}\n{}\n{}\n\n{}\n'.format(description,
                                            definition, fields, variable)
    return result


def generate_peripheral(per):
    lower_name = per.name.lower()
    output_path = (output_dir_path / lower_name).with_suffix('.hpp')

    contents = ''
    for register in per.registers:
        contents += '{}\n'.format(generate_register(per.base_address, register))

    file_string = '{}{}'.format(
        header_start, in_namespace('avrcpp::attiny24a::m{}'.format(per.name.lower()), contents))

    f = output_path.open("w")
    f.write(file_string)
    f.close()


parser = SVDParser.for_xml_file(svd_path)

for peripheral in parser.get_device().peripherals:
    print("%s @ 0x%08x" % (peripheral.name, peripheral.base_address))
    generate_peripheral(peripheral)
