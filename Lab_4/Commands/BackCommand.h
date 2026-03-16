#pragma once
#include "ICommand.h"
#include <functional>

class BackCommand : public ICommand
{
	public:
	    explicit BackCommand(std::function<void()> onBack) : m_OnBack(onBack) {}
	    
		void Execute() override 
		{ 
			if (m_OnBack)
			{
				m_OnBack(); 
			}
		}


	private:
    	std::function<void()> m_OnBack;
};
