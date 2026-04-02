#include <glad/glad.h>

class VBO {

public:
    VBO(float vertices[], GLenum usage) {
        m_vertices = vertices;
        m_usage = usage;
    }
    void Create();

    unsigned int VBO;

private:
    float m_vertices[];
    GLenum m_usage;
}
