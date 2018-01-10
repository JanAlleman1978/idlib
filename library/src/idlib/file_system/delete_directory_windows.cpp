#include "idlib/file_system/delete_directory_windows.hpp"

#if defined (ID_WINDOWS)

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

#include "idlib/file_system/header.in"

bool delete_directory_impl(const std::string& filename)
{
    if (filename.empty())
    {
        return false;
    }
    return (0 != RemoveDirectoryA(filename.c_str())) ? true : false;
}

#include "idlib/file_system/footer.in"

#endif
