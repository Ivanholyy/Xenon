#ifndef WINDOW_H
#define WINDOW_H 1

#include <GLFW/glfw3.h>
#include <iostream>
#include "../camera/camera.h"

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
    static void mouse_callback(GLFWwindow *window, double xposin, double yposin);
    static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

    inline GLFWwindow *getwindow() const {
        return m_window;
    }

    inline int getwidth() const {
        return m_width;
    }

    inline int getheight() const {
        return m_height;
    }

    inline CCamera &getcamera() {
        return m_camera;
    }

    float m_deltatime = 0.0f;

private:
    GLFWwindow *m_window;
    CCamera m_camera;
    int m_width;
    int m_height;
    bool m_firstmouse = true;
    float m_lastx;
    float m_lasty;
};

#endif
