#include "window.h"
#include "../log/log.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // note that width and height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
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

    m_width = width;
    m_height = height;

    return 0;
}

void CWindow::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
