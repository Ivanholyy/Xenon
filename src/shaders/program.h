#ifndef PROGRAM_H
#define PROGRAM_H 1

#include <glad/glad.h>
#include <iostream>

class CProgram {

public:
    CProgram(unsigned int vertexshader, unsigned int fragmentshader)
    : m_vertexshader(vertexshader), m_fragmentshader(fragmentshader) {}

    ~CProgram() {
        if (m_vertexshader && m_fragmentshader) {
            glDeleteShader(m_vertexshader);
            glDeleteShader(m_fragmentshader);
        }
        if (m_shaderprogram)
            glDeleteProgram(m_shaderprogram);
    }

    int Create();
    void setbool(const std::string &name, bool value) const;
    void setint(const std::string &name, int value) const;
    void setfloat(const std::string &name, float value) const;

    void use() {
        if (m_shaderprogram)
            glUseProgram(m_shaderprogram);
    }

    inline unsigned int getshaderprogram() const {
        return m_shaderprogram;
    }
private:
    unsigned int m_vertexshader;
    unsigned int m_fragmentshader;
    unsigned int m_shaderprogram;
};

#endif
