//
// Created by arran-taylor on 10/1/26.
//
#include "shader.h"

shader::shader(const std::string& vertex_file_path, const std::string& fragment_file_path) {
    const unsigned int vertex_shader_id = create_shader_module(vertex_file_path, GL_VERTEX_SHADER);
    const unsigned int fragment_shader_id = create_shader_module(fragment_file_path, GL_FRAGMENT_SHADER);

    shader_id = glCreateProgram();

    // Attach shader modules to the main shader program
    glAttachShader(shader_id, vertex_shader_id);
    glAttachShader(shader_id, fragment_shader_id);

    // Attempt to link the main shader program
    glLinkProgram(shader_id);

    // Check for program linking success
    int success;
    glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
    if (!success) {
        char info_log[1024];
        glGetProgramInfoLog(shader_id, 1024, nullptr, info_log);
        std::cerr << "Failed to link shader modules:\n" << info_log << std::endl;
        exit(1);
    }

    // Delete unused shader modules
    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);
}

shader::shader() = default;

unsigned int shader::get_shader_id() const {
    return shader_id;
}

shader::operator unsigned int() const {
    return shader_id;
}

unsigned int shader::create_shader_module(const std::string &file_path, unsigned int shader_type) {
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
        std::cerr << "Failed to compile shader module:\n" << info_log << std::endl;
        exit(1);
    }

    return shader_id;
}


