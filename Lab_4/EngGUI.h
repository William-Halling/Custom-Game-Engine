#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Texture.h"


class EngGUI
{
    public:
        EngGUI();
        ~EngGUI();

        void BeginFrame();
        void EndFrame();
        void Render();

        void ShowDemoWindow(bool show) { m_ShowDemo = show; }
        void isDemoVisible() const     { return m_ShowDemo; }
        void SetGroupPhotoTexture(unsigned int texID) { m_GroupPhotoTex = texID; }

private:
    GLFWwindow* m_Window;
    bool m_ShowDemo = true;
    bool m_ShowImage = false;
    unsigned int m_GroupPhotoTex = 0;
};
