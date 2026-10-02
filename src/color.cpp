//
// Created by arran-taylor on 10/2/26.
//
#include "color.h"

color::color(const float r, const float g, const float b, const float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

color::color(const float r, const float g, const float b) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = 1.0f;
}
