#ifndef WINDOW_H
#define WINDOW_H 1

#include <GLFW/glfw3.h>
#include <iostream>

class CWindow {

public:
    CWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
    }

    ~CWindow() {
        glfwTerminate();
    }

    int Create(int width, int height, std::string name);
    void processInput(GLFWwindow *window);
    inline GLFWwindow *getwindow() const {
        return m_window;
    }

    inline int getwidth() const {
        return m_width;
    }

    inline int getheight() const {
        return m_height;
    }
private:
    GLFWwindow *m_window;
    int m_width;
    int m_height;
};

#endif
