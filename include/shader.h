//
// Created by arran-taylor on 10/1/26.
//
#pragma once
#include "config.h"

class Shader {
public:
    Shader(const std::string& vertex_file_path, const std::string& fragment_file_path);
    ~Shader();
    [[nodiscard]] unsigned int get_shader_id() const;
    operator unsigned int() const;
private:
    unsigned int create_shader_module(const std::string& file_path, unsigned int shader_type);

    unsigned int shader_id;
};