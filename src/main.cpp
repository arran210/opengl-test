//
// Created by arran-taylor on 10/1/26.
//
#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) w{
    glViewport(0, 0, width, height);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialise GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(
        1280,
        720,
        "opengl-test",
        nullptr,
        nullptr
    );

    if (!window) {
        std::cerr << "Failed to create GLFW window\n";

        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    int version = gladLoadGL(glfwGetProcAddress);

    if (version == 0) {
        std::cerr << "Failed to initialise GLAD\n";

        glfwDestroyWindow(window);
        glfwTerminate();

        return -1;
    }

    glViewport(0, 0, 1280, 720);

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << '\n';

    float tri_vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    while (!glfwWindowShouldClose(window)) {

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }


        glClearColor(
            0.1f,
            0.1f,
            0.15f,
            1.0f
        );

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}