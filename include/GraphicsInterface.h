#pragma once

// We load the gl libraries here based on the macro defined.
// TODO: implement multiple backend

#ifdef GI_USE_GLAD
#include "GraphicsInterface/gl_glad.h"
#endif

#ifdef GI_USE_GLFW
#include "GraphicsInterface/gl_glfw.h"
#endif

#ifdef GI_USE_IMGUI
#include "GraphicsInterface/ui_imgui.h"
#endif


