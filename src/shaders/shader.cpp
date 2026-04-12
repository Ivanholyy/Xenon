#include "shader.h"
#include "../log/log.h"

int CShader::Compile() {

    shader = glCreateShader(m_shaderType);

    const char* src = m_buf.c_str();
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

}
