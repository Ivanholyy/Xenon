#ifndef SHADER_H
#define SHADER_H 1

#include <glad/glad.h>
#include <iostream>

class CShader {

public:
    CShader(const std::string &buf, GLenum shadertype)
          : m_buf(buf), m_shaderType(shadertype) {}

    int Compile();

    inline unsigned int getshader() const {
        return shader;
    }
private:
    std::string m_buf;
    GLenum m_shaderType;
    unsigned int shader;
};

#endif
