//
// Created by arran-taylor on 10/1/26.
//
#pragma once
#include "config.h"

class Shader {
public:
    Shader(const std::string& file_path, int shader_type);
    [[nodiscard]] unsigned int get_shader_id() const;
    operator unsigned int() const;
private:
    unsigned int shader_id;
};