cmake_minimum_required(VERSION 3.30)

project(
  GraphicsInterface
  DESCRIPTION "Wrapper Library for Graphics Programming in C++"
  LANGUAGES C CXX)

# --------------------------
# C / C++ standards
# --------------------------
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------
# External directories
# --------------------------
set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external")
set(GLAD_DIR "${EXTERNAL_DIR}/glad")
set(IMGUI_DIR "${EXTERNAL_DIR}/imgui")
set(STB_DIR "${EXTERNAL_DIR}/stb")
set(GLFW_DIR "${EXTERNAL_DIR}/glfw")
set(GLM_DIR "${EXTERNAL_DIR}/glm")

# --------------------------
# Dependency toggles
# --------------------------
option(GI_USE_GLAD "Enable GLAD" ON)
option(GI_USE_GLFW "Enable GLFW" ON)
option(GI_USE_IMGUI "Enable ImGui" ON)
option(GI_USE_GLM "Enable GLM" ON)
option(GI_USE_STB "Enable stb" ON)

# STB features
option(GI_USE_STB_IMAGE "Enable STB image support" ON)
option(GI_USE_STB_IMAGE_WRITE "Enable STB image write support" OFF)

# GLM optimizations
option(GI_GLM_FAST_MATH "Enable fast math in GLM" ON)
option(GI_GLM_USE_SSE2 "Enable SSE2 SIMD in GLM" ON)
option(GI_GLM_USE_AVX "Enable AVX SIMD in GLM" ON)

if(GI_USE_GLM)
  if(GI_GLM_FAST_MATH)
    set(GLM_FORCE_FAST_MATH
        ON
        CACHE BOOL "")
  endif()
  if(GI_GLM_USE_SSE2)
    set(GLM_ENABLE_SIMD_SSE2
        ON
        CACHE BOOL "")
  endif()
  if(GI_GLM_USE_AVX)
    set(GLM_ENABLE_SIMD_AVX
        ON
        CACHE BOOL "")
  endif()
endif()

# --------------------------
# Add the library dependencies and show enabled dependencies
# --------------------------
set(LIBS_TO_LINK)

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

# --------------------------
# Prevent in-source builds
# --------------------------
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(
    FATAL_ERROR
      "In-source builds are not allowed. Please create a separate build directory."
  )
endif()

# --------------------------
# Default build type
# --------------------------
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE STRING "Choose build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                               "MinSizeRel" "RelWithDebInfo")
endif()

# --------------------------
# Find OpenGL
# --------------------------
find_package(OpenGL REQUIRED)

# --------------------------
# Add external libraries. see external/CMakeLists.txt
# --------------------------
add_subdirectory(${EXTERNAL_DIR})

# --------------------------
# Library sources
# --------------------------
set(PROJECT_SOURCES)

# STB wrapper sources
if(GI_USE_STB)
  if(GI_USE_STB_IMAGE)
    list(APPEND PROJECT_SOURCES src/wrapper/stb/gi_stb_image.cpp)
  endif()
  if(GI_USE_STB_IMAGE_WRITE)
    list(APPEND PROJECT_SOURCES src/wrapper/stb/gi_stb_image_write.cpp)
  endif()
endif()

# --------------------------
# Define the library
# --------------------------
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_library(GraphicsInterface ${PROJECT_SOURCES})

# Include directories
target_include_directories(GraphicsInterface
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link dependencies
target_link_libraries(GraphicsInterface PUBLIC OpenGL::GL ${LIBS_TO_LINK})

# Alias target for easier usage downstream
add_library(GraphicsInterface::GraphicsInterface ALIAS GraphicsInterface)

# Export compile commands for IDEs / tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
