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

# External directories
set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external")
set(GLAD_DIR "${EXTERNAL_DIR}/glad")
set(IMGUI_DIR "${EXTERNAL_DIR}/imgui")
set(STB_DIR "${EXTERNAL_DIR}/stb")
set(GLFW_DIR "${EXTERNAL_DIR}/glfw")
set(GLM_DIR "${EXTERNAL_DIR}/glm")

# Build static libraries (default ON)
set(BUILD_SHARED_LIBS
    OFF
    CACHE BOOL "Build shared libraries")

# Dependency toggles (can be overridden by main project or command line)
option(GI_USE_GLAD "Enable GLAD support" ON)
option(GI_USE_GLFW "Enable GLFW support" ON)
option(GI_USE_IMGUI "Enable ImGui support" ON)
option(GI_USE_GLM "Enable GLM support" ON)
option(GI_USE_STB "Enable stb support" ON)

# Show enabled dependencies
message(STATUS "Building with the following dependencies:")
if(GI_USE_GLAD)
  list(APPEND LIBS_TO_LINK glad)
  message(STATUS " - GLAD")
endif()
if(GI_USE_GLFW)
  list(APPEND LIBS_TO_LINK glfw)
  message(STATUS " - GLFW")
endif()
if(GI_USE_GLM)
  list(APPEND LIBS_TO_LINK glm)
  message(STATUS " - GLM")
endif()
if(GI_USE_IMGUI)
  list(APPEND LIBS_TO_LINK imgui)
  message(STATUS " - ImGui")
endif()
if(GI_USE_STB)
  list(APPEND LIBS_TO_LINK stb)
  message(STATUS " - stb")
endif()

# Prevent in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(
    FATAL_ERROR
      "In-source builds are not allowed. Please create a separate build directory."
  )
endif()

# Enable compile commands export for tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default build type if none specified
set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}'.")
  set(CMAKE_BUILD_TYPE
      "${default_build_type}"
      CACHE STRING "Choose build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                               "MinSizeRel" "RelWithDebInfo")
endif()

# Find OpenGL (required)
find_package(OpenGL REQUIRED)

# Add the external libraries
add_subdirectory(${EXTERNAL_DIR})

# Define your GraphicsInterface library and its sources
add_library(
  GraphicsInterface STATIC src/GraphicsInterface/gi_stb_image.cpp
                           src/GraphicsInterface/gi_stb_image_write.cpp)

# Include directories for your library (public API)
target_include_directories(GraphicsInterface
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link the dependencies
target_link_libraries(GraphicsInterface PUBLIC OpenGL::GL ${LIBS_TO_LINK})

# Create an alias target for easier usage downstream
add_library(GraphicsInterface::GraphicsInterface ALIAS GraphicsInterface)
