#include <glad/glad.h>

class Shader {

public:
    Shader(char* buf, GLenum shaderType) {
        m_buf = buf;
        m_shaderType = shaderType;
    }
    unsigned int shader;
    int Compile();

private:
    char* m_buf;
    GLenum m_shaderType;

}
