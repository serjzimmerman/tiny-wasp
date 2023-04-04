
/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <tsimmerman.ss@phystech.edu> wrote this file.  As long
 * as you retain this notice you can do whatever you want with this stuff. If we
 * meet some day, and you think this stuff is worth it, you can buy me a beer in
 * return.
 * ----------------------------------------------------------------------------
 */

#include "common.hpp"

#include <algorithm> // These two headers are needed to fix bitset
#include <type_traits>

#include <bitset>
#include <cassert>
#include <climits>
#include <concepts>
#include <cstdint>
#include <limits>

#pragma once

namespace avrcpp
{

static_assert( sizeof( uint8_t ) == 1, "Size of fixed width type `uint8_t` is not expected" );
static_assert( sizeof( uint16_t ) == 2, "Size of fixed width type `uint8_t` is not expected" );

// Stateless class to flag registers as read-only.
struct read_only_flag
{
};

// Stateless class to flag registers as write-only.
struct write_only_flag
{
};

// Flags register as being read-write.
struct read_write_flag : read_only_flag, write_only_flag
{
};

template <typename flag>
concept writable_register = std::derived_from<flag, write_only_flag>;

template <typename flag>
concept readable_register = std::derived_from<flag, read_only_flag>;

template <auto width> struct uint_of_width
{
};

template <auto width> using uint_of_width_t = typename uint_of_width<width>::type;

template <> struct uint_of_width<1>
{
    using type = uint8_t;
};

template <> struct uint_of_width<2>
{
    using type = uint16_t;
};

template <auto address, auto width, typename access> class register_wrapper
{
  public:
    using register_type = uint_of_width_t<width>;

  public:
    register_wrapper() = default;

    register_wrapper( const register_wrapper& ) = delete;
    register_wrapper( register_wrapper&& ) = delete;

    register_wrapper& operator=( const register_wrapper& ) = delete;
    register_wrapper& operator=( register_wrapper&& ) = delete;

    ~register_wrapper() = default;

  private:
    ALWAYS_INLINE volatile register_type& underlying() const
    {
        return *reinterpret_cast<volatile register_type*>( address );
    }

  public:
    ALWAYS_INLINE void set( register_type value ) const
        requires writable_register<access>
    {
        underlying() = value;
    }

    ALWAYS_INLINE register_type get() const
        requires readable_register<access>
    {
        return underlying();
    }

    ALWAYS_INLINE const register_wrapper& operator=( register_type rhs ) const
        requires writable_register<access>
    {
        set( rhs );
        return *this;
    }

  public:
    ALWAYS_INLINE const register_wrapper& operator|=( register_type rhs ) const
        requires writable_register<access>
    {
        underlying() |= rhs;
        return *this;
    }

    ALWAYS_INLINE const register_wrapper& operator&=( register_type rhs ) const
        requires writable_register<access>
    {
        underlying() &= rhs;
        return *this;
    }

    ALWAYS_INLINE const register_wrapper& operator^=( register_type rhs ) const
        requires writable_register<access>
    {
        underlying() ^= rhs;
        return *this;
    }

    ALWAYS_INLINE operator register_type() const
        requires readable_register<access>
    {
        return get();
    }
};

template <typename reg, auto bit_offset, auto bit_width> class register_field
{
  public:
    using register_type = typename reg::register_type;
    register_type underlying_value = 0;

    static constexpr uint8_t width = bit_width;
    static constexpr uint8_t offset = bit_offset;

    static_assert( bit_offset < CHAR_BIT * sizeof( register_type ) );
    static_assert( bit_width <= CHAR_BIT * sizeof( register_type ) && bit_width > 0 );

    static constexpr register_type max_representable = ( 1 << bit_width ) - 1;
    static constexpr register_type mask = max_representable;

  public:
    explicit ALWAYS_INLINE constexpr register_field( register_type value )
        : underlying_value{ static_cast<register_type>( value << offset ) }
    {
        if ( std::is_constant_evaluated() && value > max_representable )
        {
            throw "Value does not fit in the bit field"; // To cause a compilation error
        }
    }

  public:
    ALWAYS_INLINE constexpr friend register_field operator|( const register_field& lhs, const register_field& rhs )
    {
        return register_field{ lhs.underlying_value | rhs.underlying_value };
    }

    ALWAYS_INLINE constexpr friend register_field operator&( const register_field& lhs, const register_field& rhs )
    {
        return register_field{ lhs.underlying_value & rhs.underlying_value };
    }

    ALWAYS_INLINE constexpr friend register_field operator^( const register_field& lhs, const register_field& rhs )
    {
        return register_field{ lhs.underlying_value ^ rhs.underlying_value };
    }

    ALWAYS_INLINE constexpr register_field& operator|=( const register_type& rhs ) const&
    {
        underlying_value |= rhs;
        return *this;
    }

    ALWAYS_INLINE constexpr register_field& operator&=( const register_type& rhs ) const&
    {
        underlying_value &= rhs;
        return *this;
    }

    ALWAYS_INLINE constexpr register_field& operator^=( const register_type& rhs ) const&
    {
        underlying_value ^= rhs;
        return *this;
    }

    ALWAYS_INLINE constexpr operator register_type() const { return underlying_value; }
};

}; // namespace avrcpp