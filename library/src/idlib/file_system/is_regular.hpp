#pragma once

#include "idlib/utility.hpp"

#include "idlib/file_system/header.in"

/// @brief Get if a file is is an existing directory file.
/// @param pathname the pathname
/// @return @a true if a file is an existing directory file, @a false otherwise
bool is_regular(const std::string& pathname);

#include "idlib/file_system/footer.in"
