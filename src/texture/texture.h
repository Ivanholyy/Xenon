#ifndef TEXTURE_H
#define TEXTURE_H 1

#include <iostream>
#include <stb/stb_image.h>
#include <glad/glad.h>

class CTexture {

public:
    CTexture() {
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }


    int Load(const std::string &filename, GLint colorformat);

    inline unsigned int gettexture() const {
        return m_texture;
    }
private:
    int m_width;
    int m_height;
    int m_nrChannels;
    unsigned int m_texture;
};

#endif
