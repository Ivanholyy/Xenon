#include "window.h"
#include "../log/log.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // note that width and height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void CWindow::mouse_callback(GLFWwindow *window, double xposin, double yposin) {

    CWindow* self = static_cast<CWindow*>(glfwGetWindowUserPointer(window));

    float xpos = static_cast<float>(xposin);
    float ypos = static_cast<float>(yposin);

    if (self->m_firstmouse) {
        self->m_lastx = xpos;
        self->m_lasty = ypos;
        self->m_firstmouse = false;
    }

    float xoffset = xpos - self->m_lastx;
    float yoffset = self->m_lasty - ypos;

    self->m_lastx = xpos;
    self->m_lasty = ypos;

    self->m_camera.processmousemovement(xoffset, yoffset);
}

void CWindow::scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {

    CWindow *self = static_cast<CWindow*>(glfwGetWindowUserPointer(window));
    self->m_camera.processmousescroll(static_cast<float>(yoffset));
}

int CWindow::Create(int width, int height, std::string name) {

    m_window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if (m_window == NULL)
    {
        Log("Failed to create GLFW window", __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
    glfwSetCursorPosCallback(m_window, mouse_callback);
    glfwSetScrollCallback(m_window, scroll_callback);

    glfwSetWindowUserPointer(m_window, this);

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    m_width = width;
    m_height = height;

    m_lastx = width / 2.0f;
    m_lasty = height / 2.0f;

    return 0;
}

void CWindow::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        m_camera.processkeyboard(FORWARD, m_deltatime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        m_camera.processkeyboard(BACKWARD, m_deltatime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        m_camera.processkeyboard(LEFT, m_deltatime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        m_camera.processkeyboard(RIGHT, m_deltatime);
}
