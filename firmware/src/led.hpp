/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <tsimmerman.ss@phystech.edu> wrote this file.  As long
 * as you retain this notice you can do whatever you want with this stuff. If we
 * meet some day, and you think this stuff is worth it, you can buy me a beer in
 * return.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include "attiny24a/porta.hpp"

using namespace avrcpp::attiny24a::mporta;

struct led_indicator
{
    static ALWAYS_INLINE void init()
    {
        reset();
        ddra |= ddra_fields::pa7;
    }

    static ALWAYS_INLINE void set() { porta |= porta_fields::pa7; }
    static ALWAYS_INLINE void reset() { porta &= ~porta_fields::pa7; }
    static ALWAYS_INLINE void toggle() { porta ^= porta_fields::pa7; }
};