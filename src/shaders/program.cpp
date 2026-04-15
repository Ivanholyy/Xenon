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
        Log(infoLog, __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
        return -1;
    }

    return 0;
}

void CProgram::setbool(const std::string &name, bool value) const {

    glUniform1i(glGetUniformLocation(m_shaderprogram, name.c_str()), (int)value);
}

void CProgram::setint(const std::string &name, int value) const {

    glUniform1i(glGetUniformLocation(m_shaderprogram, name.c_str()), value);
}

void CProgram::setfloat(const std::string &name, float value) const {

    glUniform1f(glGetUniformLocation(m_shaderprogram, name.c_str()), value);
}
