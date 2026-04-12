#ifndef PROGRAM_H
#define PROGRAM_H 1

#include <glad/glad.h>

class CProgram {

public:
    CProgram(unsigned int vertexshader, unsigned int fragmentshader)
    : m_vertexshader(vertexshader), m_fragmentshader(fragmentshader) {}

    ~CProgram() {
        if (m_vertexshader && m_fragmentshader) {
            glDeleteShader(m_vertexshader);
            glDeleteShader(m_fragmentshader);
        }
    }

    int Create();

    inline unsigned int getshaderprogram() const {
        return m_shaderprogram;
    }
private:
    unsigned int m_vertexshader;
    unsigned int m_fragmentshader;
    unsigned int m_shaderprogram;
};

#endif
