#include "vbo.h"

void VBO::Create() {

    glGenBuffers(1, &VBO::VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO::VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, m_usage);
}
