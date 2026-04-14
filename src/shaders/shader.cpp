#include "shader.h"
#include "../log/log.h"
#include "../file.h"

int CShader::Compile() {

    shader = glCreateShader(m_shaderType);

    CFile _shader(m_filename, "r");

    if (_shader.open() == -1) {
        Log("Error while opening shaders!", __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
        return -1;
    }

    if (_shader.rfile(buf) == -1) {
        Log("Error while reading shaders!", __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
        return -1;
    }

    const char* src = buf.c_str();
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        Log(infoLog, __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
        return -1;
    }

    return 0;
}
