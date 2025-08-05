# Date Modified: 2025-07-26
cmake_minimum_required(VERSION 3.30)

project(glad C)

# Prevent multiple inclusion errors if this file is added more than once
if(TARGET glad)
  return()
endif()

# Set the glad source directory
set(GLAD_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Create a static library from glad.c source file
add_library(glad STATIC ${GLAD_DIR}/src/glad.c)

# Public include directory for anyone linking to glad
target_include_directories(glad PUBLIC ${GLAD_DIR}/include)
