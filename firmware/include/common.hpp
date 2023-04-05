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

namespace util
{

template <auto T>
consteval void
static_print()
{
#if !defined( __GNUC__ ) || defined( __clang__ )
    int _ = 0;
#else
    int _ = 0;
#endif
}

} // namespace util