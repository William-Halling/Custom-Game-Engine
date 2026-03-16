// EngGUI.cpp
#include "EngGUI.h"

EngGUI::EngGUI(GLFWwindow* window)
    : m_Window(window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr; // disable .ini file

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
}


EngGUI::~EngGUI()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}


void EngGUI::BeginFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (m_ShowDemo)
    {
        ImGui::SetNextWindowSize(ImVec2(300, 300));
        ImGui::Begin("Welcome to our Demo!");
        ImGui::Text("- Press M to open and close this manual!");
        ImGui::Text("- Press K to go into wireframe mode!");
        ImGui::Text("- Press X to quit this demo!");
        ImGui::Text("- Press WASD keys to move!");
        ImGui::Text("- Press R key to spawn boxes (test)");
        ImGui::Text("- Press the F key to fly!");
        ImGui::Text("- Use the mouse or arrow keys to look!");
        ImGui::End();

		
        if (m_ShowImage && m_GroupPhotoTex)
        {
            glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            ImGui::Begin("Image Display");
            ImGui::Image((void*)(intptr_t)m_GroupPhotoTex, ImVec2(1000, 700), ImVec2(0,1), ImVec2(1,0));
           
			
			if (ImGui::IsItemClicked())
			{
                glfwSetWindowShouldClose(m_Window, true);
			}
			ImGui::End();
			
        }
    }
}


void EngGUI::EndFrame()
{
    ImGui::Render();
}
void EngGUI::Render()
{
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
