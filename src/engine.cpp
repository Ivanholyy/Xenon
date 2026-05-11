#include <glad/glad.h>
#include "engine.h"
#include "log/log.h"
#include "shaders/shader.h"
#include "buffer/buffer.h"
#include "shaders/program.h"
#include "vao/vao.h"
#include "file.h"
#include "texture/texture.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_internal.h>
#include <imgui/imgui_impl_opengl3.h>

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

    gui.Init(&m_window);

    glEnable(GL_DEPTH_TEST);

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
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    CVao vao;

    vao.bind();

    CBuffer vbo(vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    CTexture texture;

    texture.Load("textures/wall.jpg", GL_RGB);

    stbi_set_flip_vertically_on_load(true);

    CTexture texture1;

    texture1.Load("textures/awesomeface.png", GL_RGBA);

    shaderprogram.use();
    shaderprogram.setint("texture1", 0);
    shaderprogram.setint("texture2", 1);

    while (!glfwWindowShouldClose(m_window.getwindow()))
    {
        m_window.processInput(m_window.getwindow());

        gui.Begin();

        gui.Setup();

        float currentframe = static_cast<float>(glfwGetTime());
        m_deltatime = currentframe - m_lastframe;
        m_lastframe = currentframe;

        m_window.m_deltatime = m_deltatime;

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture.gettexture());
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture1.gettexture());

        shaderprogram.use();

        glm::mat4 projection = glm::perspective(glm::radians(m_window.getcamera().zoom), (float)m_window.getwidth() / (float)m_window.getheight(), 0.1f, 100.0f);
        shaderprogram.setmat4("projection", projection);

        glm::mat4 view = m_window.getcamera().getviewmatrix();
        shaderprogram.setmat4("view", view);

        vao.bind();

        for (unsigned int i = 0; i < 10; i++) {

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);

            float angle = 20.0f * i;

            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

            shaderprogram.setmat4("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        gui.Draw();

        gui.End();

        glfwSwapBuffers(m_window.getwindow());
        glfwPollEvents();
    }

    return 0;
}
