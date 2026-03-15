#pragma once
#include <array>
#include <memory>
#include <string>

#include "MenuCommand.h"

class Player;
class BackCommand;

class LoadCommand final : public MenuCommand
{
public:

    explicit LoadCommand(std::shared_ptr<BackCommand> backCommand);

    void Execute() override;

private:

    Player LoadSavedGame(int slot) const;

    void DisplayLoadDialog();

    std::array<std::string,3> m_saveFiles;

    std::shared_ptr<BackCommand> m_backCommand;
};
