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

/// @file idlib/parsing_expressions/end_of_input.hpp
/// @brief "end of input" parsing expression.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/parsing_expressions/include.hpp` instead)
#endif

#include "idlib/parsing_expressions/match.hpp"

#include "idlib/parsing_expressions/header.in"

/// @internal
/// @brief Parsing expression accepting the end of the input.
/// @tparam Symbol the symbol type
template <typename Symbol>
struct end_of_input_expr
{
    template <typename Iterator>
    match<std::decay_t<Iterator>> operator()(Iterator at, Iterator end) const
    {
		return make_match(at == end, at, at);
    }
};

/// @brief Create a parsing expression accepting the end of the input.
/// @tparam Symbol the symbol type
/// @return the parsing expression
template <typename Symbol>
end_of_input_expr<Symbol> end_of_input()
{
	return end_of_input_expr<Symbol>();
}

#include "idlib/parsing_expressions/footer.in"
