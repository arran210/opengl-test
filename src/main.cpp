//
// Created by arran-taylor on 10/1/26.
//
#include "config.h"

#include "init.h"
#include "shader.h"

int main() {

    if (init() == -1) {
        std::cout << "Failed to initialize!" << std::endl;
        return -1;
    }

    Shader shader("../shaders/basic.vert", "../shaders/basic.frag");

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
        
        glUseProgram(shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}