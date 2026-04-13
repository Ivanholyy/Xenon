#ifndef BUFFER_H
#define BUFFER_H 1

#include <glad/glad.h>
#include <vector>

class CBuffer {

public:
    CBuffer(const std::vector<float> &vertices, GLenum usage)
       : m_vertices(vertices), m_usage(usage) {
           glGenBuffers(1, &m_buffer);
           glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
           glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), m_vertices.data(), m_usage);
       }

    CBuffer(const std::vector<unsigned int> &indices, GLenum usage)
       : m_indices(indices), m_usage(usage) {
           glGenBuffers(1, &m_buffer);
           glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer);
           glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), m_usage);
       }

    ~CBuffer() {
        if (m_buffer)
            glDeleteBuffers(1, &m_buffer);
    }

    inline unsigned int getbuffer() const {
        return m_buffer;
    }
private:
    std::vector<float> m_vertices;
    std::vector<unsigned int> m_indices;
    unsigned int m_buffer;
    GLenum m_usage;
};

#endif
