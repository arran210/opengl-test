//
// Created by arran-taylor on 10/1/26.
//
#include "config.h"

#include "init.h"
#include "shader.h"
#include "tri.h"

int main() {

    if (init() == -1) {
        std::cout << "Failed to initialize!" << std::endl;
        return -1;
    }

    tri::program = shader("../shaders/basic.vert", "../shaders/basic.frag");

    const tri triangle(
    {-0.5f, -0.5f, -0.0f },
    { 0.5f, -0.5f, -0.0f },
    { 0.0f, 0.5f,  -0.0f },
     { 1.0f, 0.5f, 0.0f, 1.0f }
     );

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

        triangle.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
