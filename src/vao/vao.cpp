#include "vao.h"
#include <glad/glad.h>

unsigned int creatvao() {

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    return VAO;
}
