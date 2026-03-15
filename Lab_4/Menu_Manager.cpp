#include "MenuManager.h"
#include "Menu.h"

void MenuManager::PushMenu(std::unique_ptr<Menu> menu)
{
	m_MenuStack.push(std::move(menu));
}


void MenuManager::PopMenu()
{
	if(!m_menuStack.empty())
	{
		m_menuStack.pop();
	}
}


void MenuManager::Draw()
{
	if(!m_menuStack.empty())
	{
		m_menuStack.top()->Draw();
	}
}


bool MenuManager::HasMenus() const
{
	return !m_menuStack.empty();
}

