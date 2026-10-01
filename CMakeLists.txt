cmake_minimum_required(VERSION 4.3)
project(opengl-test
        VERSION 1.0
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(opengl-test
        src/main.cpp
        src/gl.c
)

target_include_directories(opengl-test PRIVATE
        include
)

target_link_libraries(opengl-test PRIVATE
        glfw
        OpenGL::GL
)