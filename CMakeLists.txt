# Date Modified: 2025-07-26

cmake_minimum_required(VERSION 3.30)

project(
  GraphicsInterface
  DESCRIPTION "Library for Graphics Programming in C++"
  LANGUAGES C CXX)

# Set some C and CXX Standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build Dynamic Librarirs .so/.dll. Set to OFF We build static libs
set(BUILD_SHARED_LIBS
    OFF
    CACHE BOOL "Build shared libraries")

option(USE_GLFW "Build and link GLFW" ON)
option(USE_GLAD "Build and link GLAD" ON)
option(USE_GLM "Build and link GLM" ON)
option(USE_IMGUI "Build and link ImGui" ON)
option(USE_STB "Build and link stb" ON)

# Set which dependencies to link against
message(STATUS "Building with the following dependencies:")
if(USE_GLAD)
  list(APPEND LIBS_TO_LINK glad)
  message(STATUS " - GLAD")
endif()
if(USE_GLFW)
  list(APPEND LIBS_TO_LINK glfw)
  message(STATUS " - GLFW")
endif()
if(USE_GLM)
  list(APPEND LIBS_TO_LINK glm::glm)
  message(STATUS " - GLM")
endif()
if(USE_IMGUI)
  list(APPEND LIBS_TO_LINK imgui)
  message(STATUS " - ImGui")
endif()
if(USE_STB)
  list(APPEND LIBS_TO_LINK stb)
  message(STATUS " - stb")
endif()

# Throw error if doing an insource build. We don't want that
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. "
  )
endif()

# For better lsp integration and tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default Build type if not specified (set to "Release")
set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(
    STATUS
      "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE
      "${default_build_type}"
      CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                               "MinSizeRel" "RelWithDebInfo")
endif()

# OpenGL
find_package(OpenGL REQUIRED)

# Add the external libraries
add_subdirectory(external)

# Create a linking target library
add_library(GraphicsInterface SHARED src/dummy.cpp)

# link with the dependencies
target_link_libraries(GraphicsInterface PUBLIC OpenGL::GL ${LIBS_TO_LINK})

# export the include dirs
target_include_directories(GraphicsInterface PUBLIC include)

# Create an alias
add_library(GraphicsInterface::GraphicsInterface ALIAS GraphicsInterface)
