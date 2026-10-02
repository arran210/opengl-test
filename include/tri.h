//
// Created by arran-taylor on 10/2/26.
//
#pragma once

#include <vector>

#include "color.h"
#include "shader.h"
#include "vec3.h"

class tri {
public:
    // triangle shader
    static shader program;

    // vertices for the triangle
    std::vector<float> data;

    // color for the triangle
    color c {0, 0, 0, 0};

    // vertex buffer object
    unsigned int VBO = 0;

    // vertex array object
    unsigned int VAO = 0;

    // constructor
    tri(vec3 v1, vec3 v2, vec3 v3, color c);

    void draw() const;
};