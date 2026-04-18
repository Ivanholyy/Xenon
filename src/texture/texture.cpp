#include "texture.h"
#include "../log/log.h"

int CTexture::Load(const std::string &filename, GLint colorformat) {

    unsigned char *data = stbi_load(filename.c_str(), &m_width, &m_height, &m_nrChannels, 0);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, colorformat, m_width, m_height, 0, colorformat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        Log("Failed loading texture!", __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
        return -1;
    }

    stbi_image_free(data);

    return 0;
}
