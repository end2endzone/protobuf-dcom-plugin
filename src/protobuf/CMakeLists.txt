# CMakeLists.txt
cmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)
project(protobuf)

##############################################################################################################################################
# Standard CMake variables
##############################################################################################################################################

# Set a default build type if none was specified.
# See https://blog.kitware.com/cmake-and-the-default-build-type/
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  mark_as_advanced(CMAKE_BUILD_TYPE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Set the output folder where your program will be created
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(   LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

##############################################################################################################################################
# Global settings
##############################################################################################################################################

# Product version according to Semantic Versioning v2.0.0 https://semver.org/
SET(PROTOBUF_VERSION_MAJOR 2)
SET(PROTOBUF_VERSION_MINOR 5)
SET(PROTOBUF_VERSION_PATCH 0)
set(PROTOBUF_VERSION ${PROTOBUF_VERSION_MAJOR}.${PROTOBUF_VERSION_MINOR}.${PROTOBUF_VERSION_PATCH})

# Define installation directories
set(PROTOBUF_INSTALL_BIN_DIR      "bin")
set(PROTOBUF_INSTALL_LIB_DIR      "lib/protobuf-${PROTOBUF_VERSION}")
set(PROTOBUF_INSTALL_INCLUDE_DIR  "include/protobuf-${PROTOBUF_VERSION}")
set(PROTOBUF_INSTALL_CMAKE_DIR    ${PROTOBUF_INSTALL_LIB_DIR}) # CMake files (*.cmake) should have the same destination as the library files. Some also prefers to use "cmake".

##############################################################################################################################################
# Project settings
##############################################################################################################################################

# Prevents annoying warnings on MSVC
if (WIN32)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  add_definitions(/wd4244 /wd4267 /wd4018 /wd4355 /wd4800 /wd4251 /wd4996 /wd4146 /wd4305)

  # Silence the following error: C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\hash_map(17): error C2338: <hash_map> is deprecated and will be REMOVED. Please use <unordered_map>. You can define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
  add_definitions(-D_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS)
endif()

# Define include directories for source code.
# The specified values will not be exported.
include_directories(${PROTOBUF_ROOT}/src
                    ${PROTOBUF_ROOT}/vsprojects
)

# Fix invalid character escape \T or \P characters on Windows. On Windows, path can contains \P (like C:\Program Files\) which is invalid in CMake.
if (WIN32)
  string(REPLACE "\\" "/" PROTOBUF_ROOT ${PROTOBUF_ROOT})
endif()

##############################################################################################################################################
# Subprojects
##############################################################################################################################################

add_subdirectory(${CMAKE_SOURCE_DIR}/libprotobuf)
add_subdirectory(${CMAKE_SOURCE_DIR}/libprotoc)
add_subdirectory(${CMAKE_SOURCE_DIR}/protoc)

##############################################################################################################################################
# Install
##############################################################################################################################################

# Install locations:   See https://unix.stackexchange.com/a/36874
#   On UNIX, installs to "/usr/local".
#   On Windows, installs to "C:\Program Files (x86)\${PROJECT_NAME}" or to "C:\Program Files\${PROJECT_NAME}" for 64 bit binaries

# Target config version verification file
configure_file(${CMAKE_SOURCE_DIR}/cmake/protobuf-config-version.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/cmake/protobuf-config-version.cmake @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cmake/protobuf-config-version.cmake DESTINATION ${PROTOBUF_INSTALL_CMAKE_DIR})

# Target config file
configure_file(${CMAKE_SOURCE_DIR}/cmake/protobuf-config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/cmake/protobuf-config.cmake @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cmake/protobuf-config.cmake DESTINATION ${PROTOBUF_INSTALL_CMAKE_DIR})

install(EXPORT protobuf-targets DESTINATION ${PROTOBUF_INSTALL_CMAKE_DIR})
