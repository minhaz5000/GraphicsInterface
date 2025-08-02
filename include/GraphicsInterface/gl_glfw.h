#pragma once

#ifdef __gl_h_
#error "Include glad before glfw to prevent OpenGL header conflicts."
#endif

#ifdef GI_USE_GLFW

#ifdef GI_USE_GLAD
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>

#endif
