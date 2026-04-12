#include <glad/glad.h>
#include "engine.h"
#include "log/log.h"
#include "shaders/shader.h"
#include "vbo/vbo.h"
#include "shaders/program.h"
#include "vao/vao.h"

int CEngine::Init() {

    if (m_window.Create(800, 600, "Xenon") == -1) {
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Log("Failed to initialize GLAD", __LINE__, __FILE__, __PRETTY_FUNCTION__);
        return -1;
    }

    return 0;
}

int CEngine::Run() {

    std::vector<float> vertices = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    CVBO vbo(vertices, GL_STATIC_DRAW);

    vbo.Create();

    unsigned int vao = creatvao();

    CShader vertexshader("../src/shaders/vertex/vertexshader.glsl", GL_VERTEX_SHADER);

    if (vertexshader.Compile() == -1)
        return -1;

    CShader fragmentshader("../src/shaders/fragment/fragmentshader.glsl", GL_FRAGMENT_SHADER);

    if (fragmentshader.Compile() == -1)
        return -1;

    CProgram shaderprogram(vertexshader.getshader(), fragmentshader.getshader());

    if (shaderprogram.Create() == -1)
        return -1;

    while (!glfwWindowShouldClose(m_window.getwindow()))
    {
        m_window.processInput(m_window.getwindow());

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glUseProgram(shaderprogram.getshaderprogram());

        glBindVertexArray(vao);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(m_window.getwindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
