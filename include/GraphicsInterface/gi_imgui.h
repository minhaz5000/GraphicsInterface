#pragma once

// ImGui core
#include <imgui.h>

// Backend: we assume GLFW + OpenGL3, unless user defines otherwise
#ifndef GI_DISABLE_IMGUI_BACKEND_GLFW_OPENGL

    // Optional safety: ensure GLAD is included first if you're using it
    #ifdef GI_USE_GLAD
        #include <glad/glad.h>
    #endif

    // Optional safety: ensure GLFW is included
    #ifdef GI_USE_GLFW
        #include <GLFW/glfw3.h>
    #endif

    #include <imgui_impl_glfw.h>
    #include <imgui_impl_opengl3.h>

#endif // GI_DISABLE_IMGUI_BACKEND_GLFW_OPENGL
