#include "BackCommand.h"
#include "MenuManager.h"

BackCommand::BackCommand(MenuManager& manager)
    : m_manager(manager)
{
}


void BackCommand::Execute()
{
    m_manager.PopMenu();
}
