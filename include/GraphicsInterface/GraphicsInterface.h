#pragma once

// ======= Master Macros =======

// Enable everything if GI_ENABLE_ALL is defined
#ifdef GI_ENABLE_ALL
    #define GI_USE_GLAD
    #define GI_USE_GLFW
    #define GI_USE_IMGUI
    #define GI_USE_GLM
    #define GI_USE_STB_IMAGE
    #define GI_USE_STB_IMAGE_WRITE
#endif

// Disable everything if GI_DISABLE_ALL is defined
#ifdef GI_DISABLE_ALL
    #undef GI_USE_GLAD
    #undef GI_USE_GLFW
    #undef GI_USE_IMGUI
    #undef GI_USE_GLM
    #undef GI_USE_STB_IMAGE
    #undef GI_USE_STB_IMAGE_WRITE
#endif

// ======= Default Core Features =======
// These are enabled unless explicitly disabled or GI_DISABLE_ALL is defined

#ifndef GI_DISABLE_ALL
    #ifndef GI_USE_GLAD
        #define GI_USE_GLAD
    #endif
    #ifndef GI_USE_GLFW
        #define GI_USE_GLFW
    #endif
#endif

// ======= Conditional Includes =======

#ifdef GI_USE_GLAD
    #include "GraphicsInterface/gi_glad.h"
#endif

#ifdef GI_USE_GLFW
    #include "GraphicsInterface/gi_glfw.h"
#endif

#ifdef GI_USE_IMGUI
    #include "GraphicsInterface/gi_imgui.h"
#endif

#ifdef GI_USE_GLM
    #include "GraphicsInterface/gi_glm.h"
#endif

#ifdef GI_USE_STB_IMAGE
    #include "GraphicsInterface/gi_stb_image.h"
#endif

#ifdef GI_USE_STB_IMAGE_WRITE
    #include "GraphicsInterface/gi_stb_image_write.h"
#endif
