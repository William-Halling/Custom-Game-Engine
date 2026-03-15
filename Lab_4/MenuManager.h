#pragma once
#include <stack>
#include <memory>

class Menu;

class MenuManager
{
	public:
		MenuManager() = default;
		~MenuManager() = default;

		void pusheMenu(std::unique_ptr<Menu> menu);
		void popMenu();

		void Draw();
		bool HasMenus() const;

	private:
		std::stack<std::unique_ptr<Menu>> m_menuStack;
};
