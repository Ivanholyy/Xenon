#include "program.h"
#include "../log/log.h"
#include <glm/gtc/type_ptr.hpp>

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

void CProgram::setvec2(const std::string &name, const glm::vec2 value) const {

    glUniform2fv(glGetUniformLocation(m_shaderprogram, name.c_str()), 1, glm::value_ptr(value));
}

void CProgram::setvec3(const std::string &name, const glm::vec3 value) const {

    glUniform3fv(glGetUniformLocation(m_shaderprogram, name.c_str()), 1, glm::value_ptr(value));
}

void CProgram::setvec4(const std::string &name, const glm::vec4 value) const {

    glUniform4fv(glGetUniformLocation(m_shaderprogram, name.c_str()), 1, glm::value_ptr(value));
}

void CProgram::setmat2(const std::string &name, const glm::mat2 mat) const {

    glUniformMatrix2fv(glGetUniformLocation(m_shaderprogram, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void CProgram::setmat3(const std::string &name, const glm::mat3 mat) const {

    glUniformMatrix3fv(glGetUniformLocation(m_shaderprogram, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void CProgram::setmat4(const std::string &name, const glm::mat4 mat) const {

    glUniformMatrix4fv(glGetUniformLocation(m_shaderprogram, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}
