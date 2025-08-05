#pragma once

#ifdef GI_USE_STB_IMAGE

    #ifdef GI_BUILDING_LIBRARY
        #include <stb_image_write.h>
    #else
        #include <stb/stb_image_write.h>
    #endif

#endif
