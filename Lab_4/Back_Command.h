#pragma once

#include "MenuCommand.h"

class MenuManager;

class BackCommand final : public MenuCommand
{
	public:
	
	    explicit BackCommand(MenuManager& manager);
	
	    void Execute() override;
	
	private:
	
	    MenuManager& m_manager;
};
