# External dependencies for the project

# ------------------------------------------------------------
# GLAD
# ------------------------------------------------------------
if(GI_USE_GLAD)
  # GLAD OpenGL 4.6 Core Profile generated from https://gen.glad.sh/
  add_subdirectory("${GLAD_DIR}" EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------
# GLFW
# ------------------------------------------------------------
if(GI_USE_GLFW)
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
  add_subdirectory(${GLFW_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------
# GLM
# ------------------------------------------------------------
if(GI_USE_GLM)
  # GLM is header-only, no need to build a compiled library
  set(GLM_BUILD_LIBRARY
      OFF
      CACHE BOOL "")
  set(GLM_BUILD_INSTALL
      OFF
      CACHE BOOL "")
  set(GLM_BUILD_TESTS
      OFF
      CACHE BOOL "")
  add_subdirectory(${GLM_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------
# ImGui
# ------------------------------------------------------------
if(GI_USE_IMGUI)
  add_library(
    imgui
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp)
  target_include_directories(imgui PUBLIC ${IMGUI_DIR} ${IMGUI_DIR}/backends)

  target_link_libraries(imgui PUBLIC OpenGL::GL)
  if(GI_USE_GLFW)
    target_link_libraries(imgui PUBLIC glfw)
  endif()
endif()

# ------------------------------------------------------------
# stb
# ------------------------------------------------------------
if(GI_USE_STB)
  add_library(stb INTERFACE)
  target_include_directories(stb INTERFACE ${STB_DIR})
endif()
