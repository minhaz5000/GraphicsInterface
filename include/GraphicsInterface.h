#pragma once

// ======================
// GraphicsInterface Master Header
// ======================

// ======= Master Feature Macros =======

// Enable all features if GI_ENABLE_ALL is defined
#ifdef GI_ENABLE_ALL
    #define GI_USE_GLAD
    #define GI_USE_GLFW
    #define GI_USE_IMGUI
    #define GI_USE_GLM
    #define GI_USE_STB_IMAGE
    #define GI_USE_STB_IMAGE_WRITE
#endif

// Disable all features if GI_DISABLE_ALL is defined
#ifdef GI_DISABLE_ALL
    #undef GI_USE_GLAD
    #undef GI_USE_GLFW
    #undef GI_USE_IMGUI
    #undef GI_USE_GLM
    #undef GI_USE_STB_IMAGE
    #undef GI_USE_STB_IMAGE_WRITE
#endif

// ======= Default Core Features =======
// Enable GLAD and GLFW by default unless explicitly disabled
#ifndef GI_DISABLE_ALL
    #ifndef GI_USE_GLAD
        #define GI_USE_GLAD
    #endif
    #ifndef GI_USE_GLFW
        #define GI_USE_GLFW
    #endif
#endif

// ======================
// Conditional Includes
// ======================

#ifdef GI_USE_GLAD
    #include <glad/glad.h>
#endif

#ifdef GI_USE_GLFW
    #include <GLFW/glfw3.h>
#endif

#ifdef GI_USE_IMGUI
    #include <imgui.h>

    // Default backend: GLFW + OpenGL3
    #ifndef GI_DISABLE_IMGUI_BACKEND_GLFW_OPENGL
        #ifdef GI_USE_GLAD
            #include <glad/glad.h>
        #endif
        #ifdef GI_USE_GLFW
            #include <GLFW/glfw3.h>
        #endif
        #include <imgui_impl_glfw.h>
        #include <imgui_impl_opengl3.h>
    #endif
#endif

#ifdef GI_USE_GLM
    #include <glm/glm.hpp>
    #include <glm/gtc/matrix_transform.hpp>
    #include <glm/gtc/type_ptr.hpp>
    #include <glm/gtx/quaternion.hpp>
#endif

#ifdef GI_USE_STB_IMAGE
    #include <stb_image.h>
#endif

#ifdef GI_USE_STB_IMAGE_WRITE
    #include <stb_image_write.h>
#endif
