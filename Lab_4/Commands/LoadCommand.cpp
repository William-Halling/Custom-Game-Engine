#include "LoadCommand.h"
#include "Player.h"
#include "BackCommand.h"

#include <fstream>
#include <iostream>
#include <glm/glm.hpp>
#include <imgui.h>

LoadCommand::LoadCommand(std::shared_ptr<BackCommand> backCommand)
    : m_backCommand(std::move(backCommand))
{
    m_saveFiles =
    {
        "saveOne.txt",
        "saveTwo.txt",
        "saveThree.txt"
    };
}


void LoadCommand::Execute()
{
    DisplayLoadDialog();
}


void LoadCommand::DisplayLoadDialog()
{
    if (ImGui::Begin("Load Game"))
    {
        for (int i = 0; i < 3; ++i)
        {
            if (ImGui::Button(("Load " + std::to_string(i + 1)).c_str()))
            {
                Player player = LoadSavedGame(i + 1);

                std::cout << "Loaded Player: " << player.GetPlayerName() << " | Score: " << player.GetPlayerScore() << std::endl;
            }
            ImGui::Text("%s", m_saveFiles[i].c_str());
        }

		
        if (ImGui::Button("Back"))
        {
            m_backCommand->Execute();
        }

        ImGui::End();
    }
}
