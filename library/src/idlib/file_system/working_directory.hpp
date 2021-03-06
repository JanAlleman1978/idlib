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

/// @file idlib/file_system/working_directory.hpp
/// @brief Determine the working directory.
/// @author Michael Heilmann

#pragma once

#include "idlib/platform.hpp"
#include <string>

#include "idlib/file_system/header.in"

/// @brief Get the current working directory of this process.
/// @return the current working directory of this process
/// @throw std::runtime_error the current working directory can not be obtained
/// @throw std::bad_alloc an out of memory situation occurred
std::string get_working_directory();

#include "idlib/file_system/footer.in"
