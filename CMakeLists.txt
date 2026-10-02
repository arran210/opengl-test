cmake_minimum_required(VERSION 4.2)
project(opengl-test
        VERSION 1.0
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

if (WIN32)

    message("Configuring for Windows:")

    # 1. Fetch GLFW directly from GitHub
    include(FetchContent)
    FetchContent_Declare(
            glfw
            GIT_REPOSITORY https://github.com/glfw/glfw
            GIT_TAG        3.4 # Use the specific version you need
    )

    # 2. Disable building GLFW documentation, tests, and examples to save compile time
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")

    FetchContent_MakeAvailable(glfw)

elseif(UNIX)

    message("Configuring for Linux")

    # Fetch package direct from computer
    find_package(glfw)

endif ()


add_executable(opengl-test
        src/main.cpp
        src/gl.c
        src/init.cpp
        include/config.h
        include/init.h
        src/shader.cpp
        include/shader.h
        src/tri.cpp
        include/tri.h
        include/vec2.h
        src/vec2.cpp
        include/math.h
        src/color.cpp
        include/color.h
        src/vec3.cpp
        include/vec3.h
)

target_include_directories(opengl-test PRIVATE
        include
)

target_link_libraries(opengl-test PRIVATE
        glfw
        OpenGL::GL
)