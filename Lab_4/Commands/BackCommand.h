#pragma once

#include "ICommand.h"

class MenuManager;

class BackCommand final : public ICommand
{
	public:
	
	    explicit BackCommand(MenuManager& manager);
	
	    void Execute() override;
	
	private:
	
	    MenuManager& m_manager;
};
