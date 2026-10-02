//
// Created by arran-taylor on 10/2/26.
//
#include "tri.h"
#include "config.h"

shader tri::program;

tri::tri(const vec3 v1, const vec3 v2, const vec3 v3, const color c) {
    data.reserve(9);
    data.push_back(v1.x);
    data.push_back(v1.y);
    data.push_back(v1.z);
    data.push_back(v2.x);
    data.push_back(v2.y);
    data.push_back(v2.z);
    data.push_back(v3.x);
    data.push_back(v3.y);
    data.push_back(v3.z);

    this->c = c;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
}

void tri::draw() const {
    glUseProgram(program);

    const int vertex_color_location = glGetUniformLocation(program, "fragmentColor");
    glUniform4f(vertex_color_location, c.r, c.g, c.b, c.a);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);


}
