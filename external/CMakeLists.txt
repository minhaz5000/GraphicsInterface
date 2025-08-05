# Date Modified: 2025-07-26
cmake_minimum_required(VERSION 3.30)

# ##############################################################################
if(GI_USE_GLAD)
  # GLAD OpenGL 4.6 Core Profile generated from https://gen.glad.sh/

  # Create a glad target library

  # Add glad library
  add_subdirectory("${GLAD_DIR}")

endif()

if(GI_USE_GLFW)
  # GLFW

  # Turn off some unnecessary things like tests, docs, etc.
  set(GLFW_BUILD_EXAMPLES
      OFF
      CACHE BOOL "")
  set(GLFW_BUILD_TESTS
      OFF
      CACHE BOOL "")
  set(GLFW_BUILD_DOCS
      OFF
      CACHE BOOL "")
  set(GLFW_INSTALL
      OFF
      CACHE BOOL "")

  add_subdirectory("${GLFW_DIR}")

endif()

# ##############################################################################

if(GI_USE_GLM)
  # GLM

  # Enable C++20
  set(GLM_ENABLE_CXX_20
      ON
      CACHE BOOL "")
  # Disable language extensions to enforce strict standards compliance
  set(GLM_ENABLE_LANG_EXTENSIONS
      OFF
      CACHE BOOL "")
  # Enable fast math approximations (better performance, less precision)
  set(GLM_FORCE_FAST_MATH
      ON
      CACHE BOOL "")
  # Enable SIMD optimizations (performance boost, only if supported by your
  # target CPU)
  set(GLM_ENABLE_SIMD_SSE2
      ON
      CACHE BOOL "")
  set(GLM_ENABLE_SIMD_AVX
      ON
      CACHE BOOL "")
  set(GLM_BUILD_LIBRARY
      ON
      CACHE BOOL "")
  # Disable install and test targets unless you need them
  set(GLM_BUILD_INSTALL
      OFF
      CACHE BOOL "")
  set(GLM_BUILD_TESTS
      OFF
      CACHE BOOL "")

  # Add GLM
  add_subdirectory("${GLM_DIR}")

endif()

# ##############################################################################

if(GI_USE_IMGUI)
  # Dear Imgui Library

  # As there is no CMake build system provided by source, we create one
  # ourselves

  # we use GLFW and OpenGL in imgui

  # Create a target library called imgui
  add_library(
    imgui
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp)

  target_include_directories(imgui PUBLIC ${IMGUI_DIR} ${IMGUI_DIR}/backends)

  # Link with glfw as it is a dependency
  target_link_libraries(imgui PUBLIC OpenGL::GL glfw)

endif()

# ##############################################################################
if(GI_USE_STB)
  # stb header only utilities

  # Header only library so we create an INTERFACE target
  add_library(stb INTERFACE)
  target_include_directories(stb INTERFACE ${STB_DIR})
endif()
