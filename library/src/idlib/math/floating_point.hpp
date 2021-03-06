///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Idlib: A C++ utility library
// Copyright (C) 2017-2018 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @file id/math/interpolate.hpp
/// @brief Functionality to interpolate between floating point values.
/// @author Michael Heilmann

#pragma once

#include "idlib/math/interpolate.hpp"
#include "idlib/math/mu.hpp"
#include "idlib/math/one_zero.hpp"
#include "idlib/math/is_negative.hpp"
#include "idlib/math/is_positive.hpp"

#include <type_traits>
#include <cmath>

namespace idlib {
	
/// @ingroup math
/// @brief Get if a floating point value is not a number.
/// @param x the floating point value
/// @return @a true if the floating point value @a x is not a number, @a false otherwise
template<class T>
std::enable_if_t<std::is_floating_point<T>::value, bool>
is_not_a_number(T x)
{
	return (std::fpclassify(x) == FP_NAN);
}

/// @ingroup math
/// @brief Get if a floating point value is positive infinity.
/// @param x the floating point value
/// @return @a true if the floating point value @a x is positive infinity, @a false otherwise
template<class T>
std::enable_if_t<std::is_floating_point<T>::value, bool>
is_positive_infinity(T x)
{
	return (x > 0 && std::fpclassify(x) == FP_INFINITE);
}

/// @ingroup math
/// @brief Get if a floating point value is negative infinity.
/// @param x the floating point value
/// @return @a true if the floating point value @a x is negative infinity, @a false otherwise
template<class T>
std::enable_if_t<std::is_floating_point<T>::value, bool>
is_negative_infinity(T x)
{
	return (x < 0 && std::fpclassify(x) == FP_INFINITE);
}

/// @ingroup math
/// @brief Get if a floating point value is infinity.
/// @param x the floating point value
/// @return @a true if the floating point value @a x is infinity, @a false otherwise
template<class T>
std::enable_if_t<std::is_floating_point<T>::value, bool>
is_infinity(T x)
{
	return (std::fpclassify(x) == FP_INFINITE);
}

/// @ingroup math
/// @brief Get if a floating point value is bad.
/// @param x the floating point value
/// @return @a true if a the floating point value @a x is bad, @a false otherwise
/// @remark A floating point value is bad if its infinity or not a number.
template<class T>
std::enable_if_t<std::is_floating_point<T>::value, bool>
is_bad(T x)
{
	return is_infinity(x) || is_not_a_number(x);
}

/// @ingroup math
/// @brief Enumerations of the outcome of an equality check for floating-point values.
enum class equality_check_result
{
	/// @brief The check did not determine wether the floating-point values are equal or not equal.
	undetermined,
	/// @brief The check determined that the floating-point values are equal.
	equal,
	/// @brief The check determined that the floating-point values are equal.
	not_equal,
};

/// @ingroup math
/// @brief Function which handles all cases of floating-point values comparison that are not "black
/// magic". If you are writing floating-point comparison code then always use this function before
/// your code. If it yields a meaningful result, then your code does not need to run.
/// @param x, y the floating point values
/// @return result::equal (result::not_equal) if @a x and @a y are determined to be equal (not equal).
///         result::undetermined is returned if this function has not determined wether @a x an @a y are equal or not equal.
/// @remark
/// The function returns result::equal if comparing @a and @a y using the the == operator  yields
/// logically @a true. Otherwise it proceeds and return result::not_equal if @a x and/or @a y are
/// /is NaN and. Otherwise it proceeds and returns result::undetermined.
template<class T>
typename std::enable_if_t<std::is_floating_point<T>::value, equality_check_result>
equal_to(T x, T y)
{
	if (x == y)
	{ 
		return equality_check_result::equal;
	}
	if (std::isnan(x) || std::isnan(y))
	{
		return equality_check_result::not_equal;
	}
	return equality_check_result::undetermined;
}
	
} // namespace idlib

namespace idlib {

/// @ingroup math
/// @brief Interpolate functor specialization for floating point types.
template <typename T>
struct lineary_interpolate_functor<T, T, std::enable_if_t<std::is_floating_point<T>::value>>
{
	using value_type = T;
	using parameter_type = T;
	
    /// @brief Interpolate between to floating point values.
    /// @param x, y the values to interpolate between
    /// @param t the parameter. Must be within the bounds of @a 0 (inclusive) and @a 1 (inclusive).
    /// @return the interpolated value
    /// @throw out_of_bounds_error @a t is not within the bounds of @a 0 (inclusive) and @a 1 (inclusive)
    auto operator()(value_type x, value_type y, parameter_type t) const
    {
        return (*this)(x, y, mu<parameter_type>(t));
    }

    /// @brief Interpolate between to floating point values.
    /// @param x, y the values to interpolate between
    /// @param t the parameter
    /// @return the interpolated value
    auto operator()(value_type x, value_type y, const mu<parameter_type>& mu) const
    {
        return x * mu.get_one_minus_mu() + y * mu.get_mu();
    }

}; // struct interpolate_functor

} // namespace idlib

namespace idlib {

/// @internal
template <>
struct zero_functor<single, void>
{
    constexpr single operator()() noexcept
    { return 0.0f; }
}; // struct zero_functor

/// @internal
template <>
struct zero_functor<double, void>
{
public:
    constexpr double operator()() noexcept
    { return 0.0; }
}; // struct zero_functor

/// @internal
template <>
struct zero_functor<quadruple, void>
{
public:
    constexpr quadruple operator()() noexcept
    { return 0.0l; }
}; // struct zero_functor

} // namespace idlib

namespace idlib {

/// @internal
template <>
struct one_functor<single, void>
{
    constexpr single operator()() noexcept
    { return 1.0f; }
}; // struct one_functor

/// @internal
template <>
struct one_functor<double, void>
{
    constexpr double operator()() noexcept
    { return 1.0; }
}; // struct one_functor

/// @internal
template <>
struct one_functor<quadruple, void>
{
    constexpr quadruple operator()() noexcept
    { return 1.0l; }
}; // struct one_functor
	
} // namespace idlib

namespace idlib {

/// @internal
template <>
struct is_negative_functor<single>
{
    bool operator()(single x) noexcept
    { return x < zero<single>(); }
}; // struct is_negative_functor

/// @internal
template <>
struct is_negative_functor<double>
{
    bool operator()(double x) noexcept
    { return x < zero<single>(); }
}; // struct is_negative_functor

/// @internal
template <>
struct is_negative_functor<quadruple>
{
    bool operator()(quadruple x) noexcept
    { return x < zero<quadruple>(); }
}; // struct is_negative_functor
	
} // namespace idlib

namespace idlib {

/// @internal
template <>
struct is_positive_functor<single>
{
    bool operator()(single x) noexcept
    { return x > zero<single>(); }
}; // struct is_positive_functor

/// @internal
template <>
struct is_positive_functor<double>
{
    bool operator()(double x) noexcept
    { return x > zero<double>(); }
}; // struct is_positive_functor

/// @internal
template <>
struct is_positive_functor<quadruple>
{
    bool operator()(quadruple x) noexcept
    { return x > zero<quadruple>(); }
}; // struct is_positive_functor
	
} // namespace idlib
