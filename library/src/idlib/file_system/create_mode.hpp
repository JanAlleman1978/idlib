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

/// @file idlib/file_system/create_mode.hpp
/// @brief Create mode for files.
/// @author Michael Heilmann

#pragma once

#include "idlib/platform.hpp"

#include "idlib/file_system/header.in"

/// @brief Enum class of file create modes.
enum class create_mode
{
    open_existing = 0,              ///< Open the file if it exists. Fail if it does not exist.
    create_not_existing = (1 << 1), ///< Create the file if it does not exist. Open the file if it exists.
	fail_existing = (1 << 2),       ///< Create the file if it does not exist. Fail if it exists.
};

#include "idlib/file_system/footer.in"
