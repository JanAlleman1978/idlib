# Minimum required CMake version.
cmake_minimum_required(VERSION 3.8)

# Project name and language.
project(idlib CXX)
message("building Idlib")


# Enable/disable compilation and execution of unit tests.
# The value of this option can be set from the command-line by -Didlib-with-tests=(ON|OFF).
option(idlib-with-tests "enable/disable compilation and execution of unit tests. ON enables compilation and execution of unit tests, OFF disables compilation and execution of unit tests. Initial value is ON." ON)

include(${CMAKE_CURRENT_SOURCE_DIR}/buildsystem/set_project_default_properties.cmake)

# Add module Google Test.
include_google_test()

# Ensure the "check" target exists.
if (NOT MSVC)
  if (NOT TARGET check)
	add_custom_target(check)
  endif()
endif()

# Add subdirectories for the library and the tests.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/library)
if (idlib-with-tests)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
