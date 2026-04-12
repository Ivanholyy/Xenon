#include "program.h"
#include "../log/log.h"

int CProgram::Create() {

    m_shaderprogram = glCreateProgram();

    glAttachShader(m_shaderprogram, m_vertexshader);
    glAttachShader(m_shaderprogram, m_fragmentshader);

    glLinkProgram(m_shaderprogram);

    int success;
    char infoLog[512];

    glGetProgramiv(m_shaderprogram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_shaderprogram, 512, NULL, infoLog);
        Log(infoLog, __LINE__, __FILE__, __PRETTY_FUNCTION__);
        return -1;
    }

    return 0;
}
