// GamePaused_State.cpp
#include "GamePaused_State.h"
#include <imgui.h>

GamePaused_State::GamePaused_State(std::shared_ptr<EngGUI> gui, std::shared_ptr<InputManager> input)
    : m_GUI(gui), m_Input(input)
{}


void GamePaused_State::Enter()
{
    // Show cursor, disable game input, etc.
}


void GamePaused_State::Exit()
{
    // Hide cursor, re-enable game input
}


void GamePaused_State::HandleInput()
{
    // Handle pause menu specific input (e.g., navigate menu)
}


void GamePaused_State::Update(float /*deltaTime*/)
{
    // Update any animations in pause menu
}


void GamePaused_State::Render()
{
    m_GUI->BeginFrame();

    if (m_ShowPauseMenu)
    {
        ImGui::Begin("Pause Menu");

        
        if (ImGui::Button("Resume"))
        {
            // Signal to state machine to pop this state
        }
        
        if (ImGui::Button("Save")) { /*...*/ }
        if (ImGui::Button("Load")) { /*...*/ }
        if (ImGui::Button("Quit")) { /*...*/ }
        
        ImGui::End();
    }

    
    m_GUI->EndFrame();
    m_GUI->Render();
}
