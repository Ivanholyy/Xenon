#ifndef SHADER_H
#define SHADER_H 1

#include <glad/glad.h>
#include <iostream>

class CShader {

public:
    CShader(const std::string &filename, GLenum shadertype)
          : m_filename(filename), m_shaderType(shadertype) {}

    int Compile();

    inline unsigned int getshader() const {
        return shader;
    }
private:
    std::string m_filename;
    GLenum m_shaderType;
    unsigned int shader;
    std::string buf;
};

#endif
