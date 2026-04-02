#include "vertex.h"
#include "../log/log.h"

int Shader::Compile() {

    shader = glCreateShader(m_shaderType);

    glShaderSource(shader, 1, &m_buf, NULL);
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
