#pragma once
#include <stack>
#include <memory>

class Menu;

class MenuManager
{
	public:
		MenuManager() = default;
		~MenuManager() = default;

		void PusheMenu(std::unique_ptr<Menu> menu);
		void PopMenu();

		void Draw();
		bool HasMenus() const;

	private:
		std::stack<std::unique_ptr<Menu>> m_menuStack;
};
