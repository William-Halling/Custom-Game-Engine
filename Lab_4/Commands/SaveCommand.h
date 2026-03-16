#pragma once
#include "ICommand.h"
#include <functional>

class SaveCommand : public ICommand
{
  public:
    SaveCommand(std::function<void(int)> saveFunc, std::function<void()> backFunc);
    void Execute() override;

  private:
    void ShowDialog();
    std::function<void(int)> m_SaveFunc;
    std::function<void()> m_BackFunc;
};
