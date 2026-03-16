// LoadCommand.cpp
#include "LoadCommand.h"
#include <imgui.h>


LoadCommand::LoadCommand(std::function<void(int)> loadFunc, std::function<void()> backFunc)
    : m_LoadFunc(loadFunc), m_BackFunc(backFunc)
{
    m_SaveFiles = {"save1.txt", "save2.txt", "save3.txt"};
}


void LoadCommand::Execute()
{
    ShowDialog();
}


void LoadCommand::ShowDialog()
{
    ImGui::Begin("Load Game");
	
    for (size_t i = 0; i < m_SaveFiles.size(); ++i)
    {
        if (ImGui::Button(("Load " + std::to_string(i+1)).c_str()))
        {
            if (m_LoadFunc)
			{
				m_LoadFunc(static_cast<int>(i+1));
        	}
		}
		
        ImGui::SameLine();
        ImGui::Text("%s", m_SaveFiles[i].c_str());
    }

	
    if (ImGui::Button("Back") && m_BackFunc)
	{
		m_BackFunc();
	}
	
	ImGui::End();
}
