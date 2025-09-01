# GraphicsInterface

A modern C++ library to simplify graphics programming by wrapping and integrating commonly used graphics dependencies.

**Features:**

- OpenGL (via GLAD)
- GLFW
- ImGui
- GLM (header-only mathematics library)
- stb

______________________________________________________________________

## Table of Contents

- [Usage](#usage)
- [Macros / Feature Toggles](#macros--feature-toggles)
- [Example Project](#example-project)
- [Building the Example](#building-the-example)
- [Notes](#notes)

______________________________________________________________________

## Usage

GraphicsInterface packages external dependencies as **submodules**. You just need to:

1. Create an `external` dir in you project dir. (you can use any name for dir)
1. Clone the github repo with the submodules in the external folder.

```bash
cd project-dir # your graphics project
mkdir external
git clone --recursive https://github.com/minhaz5000/GraphicsInterface.git external/
```

3. Add the line `add_subdirectory(external/GraphicsInterface)` in your project `CMakeLists.txt` file.

```cmake
add_subdirectory(external/GraphicsInterface)
```

4. Include the master header in your project:

```cpp
#include <GraphicsInterface.h> // Includes only glad and glfw by default
```

5. You can optionally control which features are included by defining macros before including the header:

```cpp
#define GI_DISABLE_ALL // disable everything
#define GI_USE_GLFW    // enable only GLFW
#define GI_USE_IMGUI   // enable the imgui library
#define GI_USE_GLM     // enable GLM math library
#include <GraphicsInterface/GraphicsInterface.h>
```

## Macros / Feature Toggles

| Macro | Description |
| ------------------------ | -------------------------------------------------- |
| `GI_ENABLE_ALL` | Enable all features (GLAD, GLFW, ImGui, GLM, stb) |
| `GI_DISABLE_ALL` | Disable all features |
| `GI_USE_GLAD` | Include and use GLAD |
| `GI_USE_GLFW` | Include and use GLFW |
| `GI_USE_IMGUI` | Include ImGui GUI |
| `GI_USE_GLM` | Include GLM math library |
| `GI_USE_STB_IMAGE` | Include stb_image header |
| `GI_USE_STB_IMAGE_WRITE` | Include stb_image_write header |

## Example Project

### Folder structure:

```text
MyGraphicsProject/
|--CMakeLists.txt
|--src/
|   |--main.cpp
|--external/GraphicsInterface/ \<-- cloned as submodule
```

`CMakeLists.txt` File:

```cmake

cmake_minimum_required(VERSION 3.16)
project(MyGraphicsProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GraphicsInterface submodule
add_subdirectory(external/GraphicsInterface)

# Create executable
add_executable(MyApp src/main.cpp)

# Link with GraphicsInterface
target_link_libraries(MyApp PRIVATE GraphicsInterface)
```

`src/main.cpp`

```cmake
#include <GraphicsInterface.h>
#include <glm/mat2x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main()
{
    // Your Graphics Code Here
    return 0;
}
```

### Building the Example

```bash
cmake -S . -B build
cmake --build build
./build/MyApp
```

## Notes

- Header-only libraries like GLM and stb_image can be directly used using macros or by including them.
- Compiled libraries like GLFW, GLAD, ImGui are linked automatically if you use the macros defined for them or include their headers explicitly.
