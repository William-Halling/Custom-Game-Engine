#pragma once


#include "Menu_Command.h"
#include "Menu_Manager.h"


class Back_Command : public Menu_Command
{
	public:
		Back_Command();
		Back_Command(Menu_Manager& menuManager);

		void goBack();
		void executeTask() override;

	private:
		Menu_Manager& m_MenuManager;
};
