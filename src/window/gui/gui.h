#ifndef GUI_H
#define GUI_H 1

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_internal.h>
#include <imgui/imgui_impl_opengl3.h>
#include <glad/glad.h>
#include "../window.h"

class CGUI {

public:
    ~CGUI() {
        if (ImGui::GetCurrentContext()) {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        }
    }

    void Init(CWindow *window);
    void Draw();
    void Setup();
    void Begin();
    void End();

private:
    ImVec2 m_viewportsize;
    unsigned int m_fbo;
    unsigned int m_texturecolorbuffer;
    unsigned int m_rbo;
    CWindow *m_window;
    ImVec2 m_size;
};

#endif
