# CMakeLists.txt
cmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)
project(Demo)

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
# CMake properties
##############################################################################################################################################
MESSAGE( STATUS "PROJECT_NAME:             " ${PROJECT_NAME} )
MESSAGE( STATUS "CMAKE_BINARY_DIR:         " ${CMAKE_BINARY_DIR} )
MESSAGE( STATUS "CMAKE_CURRENT_BINARY_DIR: " ${CMAKE_CURRENT_BINARY_DIR} )
MESSAGE( STATUS "CMAKE_SOURCE_DIR:         " ${CMAKE_SOURCE_DIR} )
MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR} )
MESSAGE( STATUS "PROJECT_BINARY_DIR:       " ${PROJECT_BINARY_DIR} )
MESSAGE( STATUS "PROJECT_SOURCE_DIR:       " ${PROJECT_SOURCE_DIR} )
MESSAGE( STATUS "EXECUTABLE_OUTPUT_PATH:   " ${EXECUTABLE_OUTPUT_PATH} )
MESSAGE( STATUS "LIBRARY_OUTPUT_PATH:      " ${LIBRARY_OUTPUT_PATH} )
MESSAGE( STATUS "CMAKE_MODULE_PATH:        " ${CMAKE_MODULE_PATH} )
MESSAGE( STATUS "CMAKE_COMMAND:            " ${CMAKE_COMMAND} )
MESSAGE( STATUS "CMAKE_ROOT:               " ${CMAKE_ROOT} )
MESSAGE( STATUS "CMAKE_CURRENT_LIST_FILE:  " ${CMAKE_CURRENT_LIST_FILE} )
MESSAGE( STATUS "CMAKE_CURRENT_LIST_LINE:  " ${CMAKE_CURRENT_LIST_LINE} )
MESSAGE( STATUS "CMAKE_INCLUDE_PATH:       " ${CMAKE_INCLUDE_PATH} )
MESSAGE( STATUS "CMAKE_LIBRARY_PATH:       " ${CMAKE_LIBRARY_PATH} )
MESSAGE( STATUS "CMAKE_SYSTEM:             " ${CMAKE_SYSTEM} )
MESSAGE( STATUS "CMAKE_SYSTEM_NAME:        " ${CMAKE_SYSTEM_NAME} )
MESSAGE( STATUS "CMAKE_SYSTEM_VERSION:     " ${CMAKE_SYSTEM_VERSION} )
MESSAGE( STATUS "CMAKE_SYSTEM_PROCESSOR:   " ${CMAKE_SYSTEM_PROCESSOR} )

##############################################################################################################################################
# Dependencies
##############################################################################################################################################
find_package(protobuf 2.5.0 REQUIRED NO_CMAKE_SYSTEM_PATH NO_CMAKE_PATH NO_CMAKE_SYSTEM_PACKAGE_REGISTRY )

# Manually get the location of include directories for libprotobuf
get_target_property(PROTOBUF_INCLUDE_DIRS libprotobuf INTERFACE_INCLUDE_DIRECTORIES)

##############################################################################################################################################
# Project settings
##############################################################################################################################################

# Force a debug postfix if none specified.
# This allows publishing both release and debug binaries to the same location
# and it helps to prevent linking with the wrong library on Windows.
if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX "-d")
endif()

# Prevents annoying warnings on MSVC
if (WIN32)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_library(DemoClient SHARED
  DemoClient.h
  DemoClient.cpp
)
set_target_properties(DemoClient PROPERTIES COMPILE_DEFINITIONS Demo_CLIENT_EXPORTS)

add_library(DemoProtoLib
  ErrorHandlers.h
  IComErrorProvider.h
  MessageSerializer.h
  Registry.h
  
  ErrorHandlers.cpp
  MessageSerializer.cpp
  Registry.cpp
  
  # Proto Files
  dcomplugin.pb.cc
  dcomplugin.pb.h
  Demo.pb.cc
  Demo.pb.h
  Demo.proto
  
  # Services
  IPhoneBookService.h
)

add_executable(DemoServer WIN32 
  SmartPointers.h
  DemoServer.h
  DemoServer.cpp
  DemoServer.idl
  DemoServerMain.cpp
)

add_library(DemoServerImpl
  DemoServerImpl.h
  IPhoneBookService.h
  DemoServerImpl.template.cpp
)

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(DemoClient     PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(DemoProtoLib   PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(DemoServer     PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(DemoServerImpl PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Define include directories for exported code.
target_include_directories(DemoClient     PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(DemoProtoLib   PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(DemoServer     PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(DemoServerImpl PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})

add_dependencies(DemoClient      DemoProtoLib DemoServer)
add_dependencies(DemoServer      DemoProtoLib DemoServerImpl)
add_dependencies(DemoServerImpl  DemoProtoLib)

target_link_libraries(DemoClient     PRIVATE DemoProtoLib libprotobuf)
target_link_libraries(DemoServer     PRIVATE DemoProtoLib DemoServerImpl libprotobuf)
target_link_libraries(DemoServerImpl PRIVATE DemoProtoLib)
