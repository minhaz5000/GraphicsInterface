# Date Modified: 2025-07-26

cmake_minimum_required(VERSION 3.30)

set(GLAD_DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_library(glad STATIC ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PUBLIC ${GLAD_DIR}/include)
