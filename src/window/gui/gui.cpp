#include "gui.h"
#include "../../log/log.h"
#include <vector>

extern std::vector<std::string> logbuf;

void CGUI::Init(CWindow *window) {

    m_window = window;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO(); (void)io;

    io.Fonts->AddFontFromFileTTF("fonts/roboto.ttf", 18.0f);

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGuiStyle &style = ImGui::GetStyle();

    style.WindowPadding = ImVec2(10, 10);
    style.FramePadding = ImVec2(6, 4);
    style.CellPadding = ImVec2(6, 4);
    style.ItemSpacing = ImVec2(8, 6);
    style.ItemInnerSpacing = ImVec2(6, 4);
    style.IndentSpacing = 20.0f;
    style.ScrollbarSize = 14.0f;
    style.GrabMinSize = 10.0f;

    style.WindowRounding = 6.0f;
    style.ChildRounding = 6.0f;
    style.FrameRounding = 4.0f;
    style.PopupRounding = 6.0f;
    style.ScrollbarRounding = 6.0f;
    style.GrabRounding = 4.0f;
    style.TabRounding = 5.0f;

    style.WindowBorderSize = 1.0f;
    style.FrameBorderSize = 0.0f;
    style.PopupBorderSize = 1.0f;

    ImVec4 *colors = style.Colors;

    colors[ImGuiCol_WindowBg]        = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_ChildBg]         = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_PopupBg]         = ImVec4(0.15f, 0.15f, 0.18f, 0.95f);

    colors[ImGuiCol_Border]          = ImVec4(0.20f, 0.20f, 0.23f, 0.60f);
    colors[ImGuiCol_Separator]       = ImVec4(0.25f, 0.25f, 0.28f, 0.40f);

    colors[ImGuiCol_Text]            = ImVec4(0.90f, 0.90f, 0.92f, 1.00f);
    colors[ImGuiCol_TextDisabled]    = ImVec4(0.45f, 0.45f, 0.50f, 1.00f);

    colors[ImGuiCol_Header]          = ImVec4(0.18f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_HeaderHovered]   = ImVec4(0.25f, 0.30f, 0.40f, 1.00f);
    colors[ImGuiCol_HeaderActive]    = ImVec4(0.30f, 0.35f, 0.50f, 1.00f);

    colors[ImGuiCol_Button]          = ImVec4(0.20f, 0.20f, 0.24f, 1.00f);
    colors[ImGuiCol_ButtonHovered]   = ImVec4(0.28f, 0.35f, 0.50f, 1.00f);
    colors[ImGuiCol_ButtonActive]    = ImVec4(0.35f, 0.45f, 0.65f, 1.00f);

    colors[ImGuiCol_FrameBg]         = ImVec4(0.16f, 0.16f, 0.18f, 1.00f);
    colors[ImGuiCol_FrameBgHovered]  = ImVec4(0.22f, 0.25f, 0.30f, 1.00f);
    colors[ImGuiCol_FrameBgActive]   = ImVec4(0.25f, 0.30f, 0.40f, 1.00f);

    colors[ImGuiCol_Tab]             = ImVec4(0.14f, 0.14f, 0.16f, 1.00f);
    colors[ImGuiCol_TabHovered]      = ImVec4(0.25f, 0.30f, 0.45f, 1.00f);
    colors[ImGuiCol_TabActive]       = ImVec4(0.20f, 0.25f, 0.35f, 1.00f);
    colors[ImGuiCol_TabUnfocused]    = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.18f, 0.18f, 0.22f, 1.00f);

    colors[ImGuiCol_TitleBg]         = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_TitleBgActive]   = ImVec4(0.14f, 0.14f, 0.18f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed]= ImVec4(0.08f, 0.08f, 0.10f, 1.00f);

    colors[ImGuiCol_ScrollbarBg]     = ImVec4(0.08f, 0.08f, 0.10f, 1.00f);
    colors[ImGuiCol_ScrollbarGrab]   = ImVec4(0.25f, 0.25f, 0.30f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.30f, 0.35f, 0.45f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive]  = ImVec4(0.35f, 0.40f, 0.55f, 1.00f);

    colors[ImGuiCol_CheckMark]       = ImVec4(0.45f, 0.65f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrab]      = ImVec4(0.40f, 0.60f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]= ImVec4(0.50f, 0.70f, 1.00f, 1.00f);

    colors[ImGuiCol_HeaderHovered]   = ImVec4(0.30f, 0.40f, 0.60f, 0.8f);
    colors[ImGuiCol_HeaderActive]    = ImVec4(0.35f, 0.45f, 0.70f, 1.0f);

    ImGui_ImplGlfw_InitForOpenGL(m_window->getwindow(), true);
    ImGui_ImplOpenGL3_Init("#version 330");

    glGenFramebuffers(1, &m_fbo);
    glGenTextures(1, &m_texturecolorbuffer);
    glGenRenderbuffers(1, &m_rbo);

    m_viewportsize = {(float)m_window->getwidth(), (float)m_window->getheight()};

}

void setupdockspace(ImGuiID dockspace_id) {

    static bool initialized = false;
    if (initialized) return;
    initialized = true;

    ImGui::DockBuilderRemoveNode(dockspace_id);
    ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);

    ImGuiID dock_main = dockspace_id;

    ImGuiID dock_left;
    ImGuiID dock_right;
    ImGuiID dock_bottom;

    ImGui::DockBuilderSplitNode(dock_main, ImGuiDir_Left,  1.00f, &dock_left,  &dock_main);
    ImGui::DockBuilderSplitNode(dock_main, ImGuiDir_Right, 1.00f, &dock_right, &dock_main);
    ImGui::DockBuilderSplitNode(dock_main, ImGuiDir_Down,  1.00f, &dock_bottom, &dock_main);

    ImGui::DockBuilderDockWindow("Hierarchy", dock_left);
    ImGui::DockBuilderDockWindow("Inspector", dock_right);
    ImGui::DockBuilderDockWindow("Console",   dock_bottom);
    ImGui::DockBuilderDockWindow("Content",   dock_bottom);
    ImGui::DockBuilderDockWindow("Viewport",  dock_main);

    ImGui::DockBuilderFinish(dockspace_id);
}

void CGUI::Begin() {

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void CGUI::End() {

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        GLFWwindow *backup = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup);
    }
}

void CGUI::Setup() {

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);

    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                    ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                    ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

    ImGui::Begin("Xenon Editor", nullptr, window_flags);

    if (ImGui::BeginMenuBar()) {

        if (ImGui::BeginMenu("File")) {
            ImGui::MenuItem("New Scene");
            ImGui::MenuItem("Save");
            ImGui::EndMenu();
        }
            if (ImGui::BeginMenu("Edit")) {
                ImGui::MenuItem("Undo");
                ImGui::MenuItem("Redo");
                ImGui::EndMenu();
            }
        ImGui::EndMenuBar();
    }

    ImGuiID dockspace_id = ImGui::GetID("XenonDockspace");
    ImGui::DockSpace(dockspace_id);
    setupdockspace(dockspace_id);

    ImGui::End();

    ImGui::Begin("Viewport");

    m_size = ImGui::GetContentRegionAvail();

    if (m_size.x > 0 && m_size.y > 0 && (m_size.x != m_viewportsize.x || m_size.y != m_viewportsize.y)) {
        m_viewportsize = m_size;

        glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

        glBindTexture(GL_TEXTURE_2D, m_texturecolorbuffer);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                     (int)m_size.x, (int)m_size.y,
                     0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                               GL_TEXTURE_2D, m_texturecolorbuffer, 0);

        glBindRenderbuffer(GL_RENDERBUFFER, m_rbo);
        glRenderbufferStorage(GL_RENDERBUFFER,
                              GL_DEPTH24_STENCIL8,
                              (int)m_size.x, (int)m_size.y);

        glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                                  GL_DEPTH_STENCIL_ATTACHMENT,
                                  GL_RENDERBUFFER, m_rbo);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            Log("FBO error!", __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);

            glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    glViewport(0, 0, (int)m_viewportsize.x, (int)m_viewportsize.y);
}

void CGUI::Draw() {

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    int w, h;
    glfwGetFramebufferSize(m_window->getwindow(), &w, &h);
    glViewport(0, 0, w, h);

    ImGui::Image((void*)(intptr_t)m_texturecolorbuffer,
                 m_size,
                 ImVec2(0,1),
                 ImVec2(1,0));

    ImGui::End();

    ImGui::Begin("Hierarchy");

    ImGui::End();

    ImGui::Begin("Inspector");

    ImGui::End();

    ImGui::Begin("Console");

    ImGui::BeginChild(
        "ConsoleScroll",
        ImVec2(0, 0),
        false,
        ImGuiWindowFlags_HorizontalScrollbar
    );

    for (size_t i = 0; i < logbuf.size(); i++) {
        ImGui::PushID(i);

        ImGui::PushStyleColor(ImGuiCol_Header,        ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_HeaderActive,  ImVec4(0.0f, 0.0f, 0.0f, 1.0f));

        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.80f, 0.0f, 0.0f, 1.0f));

        ImGui::Selectable(logbuf[i].c_str(), false, ImGuiSelectableFlags_AllowDoubleClick);

        ImGui::PopStyleColor(4);

        if (ImGui::BeginPopupContextItem()) {
            if (ImGui::MenuItem("Copy"))
                ImGui::SetClipboardText(logbuf[i].c_str());

            ImGui::Separator();

            if (ImGui::MenuItem("Copy All")) {
                std::string all;
                for (auto &l : logbuf)
                    all += l + "\n";

                ImGui::SetClipboardText(all.c_str());
            }

            ImGui::EndPopup();
        }

        ImGui::PopID();
    }

    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
        ImGui::SetScrollHereY(1.0f);

    ImGui::EndChild();
    ImGui::End();

    ImGui::Begin("Content");

    ImGui::End();
}
