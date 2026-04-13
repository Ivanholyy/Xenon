#ifndef VAO_H
#define VAO_H 1

#include <glad/glad.h>

class CVao {

public:
    CVao() {
        glGenVertexArrays(1, &m_vao);
    }

    ~CVao() {
        glDeleteVertexArrays(1, &m_vao);
    }

    inline unsigned int getvao() const {
        return m_vao;
    }
private:
    unsigned int m_vao;
};

#endif
