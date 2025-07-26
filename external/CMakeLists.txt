# Date Modified: 2025-07-26
cmake_minimum_required(VERSION 3.30)

# ##############################################################################
if(USE_GLAD)
  # GLAD OpenGL 4.6 Core Profile generated from https://gen.glad.sh/

  # Create a glad target library

  # Add glad library
  add_subdirectory("glad")

endif()

if(USE_GLFW)
  # GLFW

  # Turn off some unnecessary things like tests, docs and building shared libs
  set(BUILD_SHARED_LIBS OFF)
  set(GLFW_BUILD_EXAMPLES OFF)
  set(GLFW_BUILD_TESTS OFF)
  set(GLFW_BUILD_DOCS OFF)
  set(GLFW_INSTALL OFF)
  add_subdirectory("glfw")

endif()

# ##############################################################################

if(USE_GLM)
  # GLM

  # Enable C++20
  set(GLM_ENABLE_CXX_20
      ON
      CACHE BOOL "" FORCE)
  # Disable language extensions to enforce strict standards compliance
  set(GLM_ENABLE_LANG_EXTENSIONS
      OFF
      CACHE BOOL "" FORCE)
  # Enable fast math approximations (better performance, less precision)
  set(GLM_FORCE_FAST_MATH
      ON
      CACHE BOOL "" FORCE)
  # Enable SIMD optimizations (performance boost, only if supported by your
  # target CPU)
  set(GLM_ENABLE_SIMD_SSE2
      ON
      CACHE BOOL "" FORCE)
  set(GLM_ENABLE_SIMD_AVX
      ON
      CACHE BOOL "" FORCE)
  # You usually don't want to build GLM's dummy library target
  set(GLM_BUILD_LIBRARY
      OFF
      CACHE BOOL "" FORCE)
  # Disable install and test targets unless you need them
  set(GLM_BUILD_INSTALL
      OFF
      CACHE BOOL "" FORCE)
  set(GLM_BUILD_TESTS
      OFF
      CACHE BOOL "" FORCE)

  # Add GLM
  add_subdirectory("glm")

endif()

# ##############################################################################

if(USE_IMGUI)
  # Dear Imgui Library

  # As there is no CMake build system provided by source, we create one
  # ourselves

  # we use GLFW and OpenGL in imgui
  set(IMGUI_DIR imgui)

  # Create a target library called imgui
  add_library(
    imgui
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp)

  target_include_directories(
    imgui
    PUBLIC ${IMGUI_DIR}
    PUBLIC ${IMGUI_DIR}/backends)

  # Link with glfw as it is a dependency
  target_link_libraries(imgui PUBLIC OpenGL::GL glfw)

endif()

# ##############################################################################
if(USE_STB)
  # stb header only utilities

  set(STB_DIR stb)
  # Header only library so we create an INTERFACE target
  add_library(stb INTERFACE)
  target_include_directories(stb PUBLIC ${STB_DIR}/include)
endif()
