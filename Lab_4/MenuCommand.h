#pragma once

class MenuCommand
{
	public:
	    virtual ~MenuCommand() = default;
	
	    virtual void Execute() = 0;
};
