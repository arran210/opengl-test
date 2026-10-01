//
// Created by arran-taylor on 10/1/26.
//

#include "shader.h"

Shader::Shader(const std::string& file_path, int shader_type) {
    std::ifstream shader_file;
    std::stringstream buffered_lines;
    std::string line;

    shader_file.open(file_path);

    while (std::getline(shader_file, line)) {
        buffered_lines << line << "\n";
    }

    shader_file.close();

    std::string shader_source_string = buffered_lines.str();
    const char* shader_source_c_str = shader_source_string.c_str();

    shader_id = glCreateShader(shader_type);

    // Set the source code for the shader
    glShaderSource(shader_id, 1, &shader_source_c_str, nullptr);

    // Attempt to compile source code
    glCompileShader(shader_id);

    // Check shader was compiled successfully
    int success;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info_log[1024];
        glGetShaderInfoLog(shader_id, 1024, nullptr, info_log);
        std::cerr << "Failed to compile shader:\n" << info_log << std::endl;
    }
}

unsigned int Shader::get_shader_id() const {
    return shader_id;
}

Shader::operator unsigned int() const {
    return shader_id;
}


