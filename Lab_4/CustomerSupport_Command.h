// CustomerSupport_Command.h (in game directory, not engine core)
#pragma once
#include "MenuCommand.h"
#include <string>
#include <vector>
#include <memory>

class BackCommand; // forward declare

class CustomerSupport_Command : public MenuCommand
{
	public:
	    CustomerSupport_Command(std::shared_ptr<BackCommand> backCmd);
	 
		void Execute() override;
	
	private:
	    struct Availability
		{
	        std::string day;
	        std::string time;
	    };


	    std::string m_Details;
	    std::string m_ContactName;
	    std::string m_ContactEmail;
	    std::vector<Availability> m_Availability;
	    std::shared_ptr<BackCommand> m_BackCommand;
	
	    void ShowWindow();  // called by Execute to display ImGui
};
