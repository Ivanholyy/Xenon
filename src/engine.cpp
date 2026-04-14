#include <glad/glad.h>
#include "engine.h"
#include "log/log.h"
#include "shaders/shader.h"
#include "buffer/buffer.h"
#include "shaders/program.h"
#include "vao/vao.h"
#include "file.h"

int CEngine::Init() {

    if (fileexists("log/log.log")) {
        if (remove("log/log.log") != 0)
            std::cout << "Error while removing log file!" << std::endl;
    }

    if (m_window.Create(800, 600, "Xenon") == -1) {
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Log("Failed to initialize GLAD", __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
        return -1;
    }

    return 0;
}

int CEngine::Run() {

    CShader vertexshader("../src/shaders/vertex/vertexshader.glsl", GL_VERTEX_SHADER);

    if (vertexshader.Compile() == -1)
        return -1;

    CShader fragmentshader("../src/shaders/fragment/fragmentshader.glsl", GL_FRAGMENT_SHADER);

    if (fragmentshader.Compile() == -1)
        return -1;

    CProgram shaderprogram(vertexshader.getshader(), fragmentshader.getshader());

    if (shaderprogram.Create() == -1)
        return -1;

    std::vector<float> vertices = {
        0.5f,  0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
       -0.5f,  0.5f, 0.0f
    };

    std::vector<unsigned int> indices = {
        0, 1, 3,
        1, 2, 3
    };

    CVao vao;

    glBindVertexArray(vao.getvao());

    CBuffer vbo(vertices, GL_STATIC_DRAW);

    CBuffer ebo(indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    while (!glfwWindowShouldClose(m_window.getwindow()))
    {
        m_window.processInput(m_window.getwindow());

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderprogram.getshaderprogram());

        glBindVertexArray(vao.getvao());

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(m_window.getwindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
