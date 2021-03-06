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

/// @file idlib/utility.hpp
/// @brief Master include file of the Idlib utility library.
/// @author Michael Heilmann

#pragma once

#pragma push_macro("IDLIB_PRIVATE")
#undef IDLIB_PRIVATE
#define IDLIB_PRIVATE (1)

#include "idlib/utility/platform.hpp"

#include "idlib/utility/fold_expressions.hpp"

#include "idlib/utility/swap_bytes.hpp"
#include "idlib/utility/byte_order.hpp"

#include "idlib/utility/non_copyable.hpp"

#include "idlib/utility/bitmask_type.hpp"

#include "idlib/utility/exception.hpp"
#include "idlib/utility/environment_error.hpp"
#include "idlib/utility/assertion_failed_error.hpp"
#include "idlib/utility/unhandled_switch_case_error.hpp"
#include "idlib/utility/runtime_error.hpp"
#include "idlib/utility/invalid_argument_error.hpp"
#include "idlib/utility/null_error.hpp"
#include "idlib/utility/out_of_bounds_error.hpp"

#include "idlib/utility/to_upper.hpp"
#include "idlib/utility/to_lower.hpp"

#include "idlib/utility/prefix.hpp"
#include "idlib/utility/suffix.hpp"

#undef IDLIB_PRIVATE
#pragma pop_macro("IDLIB_PRIVATE")
