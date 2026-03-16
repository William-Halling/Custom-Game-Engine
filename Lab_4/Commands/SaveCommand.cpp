#include "SaveCommand.h"
#include <fstream>
#include <iostream>
#include <imgui.h>

SaveCommand::SaveCommand(const std::string& playerName, int playerScore, const std::string& playerLocation)
    : m_playerName(playerName)
    , m_playerScore(playerScore)
    , m_playerLocation(playerLocation)
{}


void SaveCommand::execute()
{
    if (ImGui::Button("Save Game"))
    {
        saveToFile("savegame.txt");
        std::cout << "Game saved.\n";
    }
}


void SaveCommand::saveToFile(const std::string& filename) const
{
    std::ofstream file(filename);
	
    if (!file.is_open())
    {
        std::cerr << "Error: could not open " << filename << " for writing.\n";
		
        return;
    }
	
    file << m_playerName  << '\n'
         << m_playerScore << '\n'
         << m_playerLocation << '\n';
}
