#pragma once
#include "PauseMenu_Commands.h"
#include <string>

class SaveCommand : public PauseMenu_Commands
{
public:
    explicit SaveCommand(const std::string& playerName, int playerScore, const std::string& playerLocation);
    void execute() override;

private:
    std::string m_playerName;
    int         m_playerScore;
    std::string m_playerLocation;

    void saveToFile(const std::string& filename) const;
};
