#ifndef VBO_H
#define VBO_H 1

#include <glad/glad.h>
#include <vector>

class CVBO {

public:
    CVBO(const std::vector<float> &vertices, GLenum usage)
       : m_vertices(vertices), m_usage(usage) {}

    void Create();

    inline unsigned int getvbo() const {
        return VBO;
    }
private:
    std::vector<float> m_vertices;
    unsigned int VBO;
    GLenum m_usage;
};

#endif
