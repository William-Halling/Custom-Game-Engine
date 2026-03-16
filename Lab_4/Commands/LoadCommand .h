#pragma once
#include "ICommand.h"
#include <string>
#include <vector>
#include <functional>


class LoadCommand : public ICommand
{
  public:
      LoadCommand(std::function<void(int)> loadFunc, std::function<void()> backFunc);
      void Execute() override;
  
  private:
    void ShowDialog();
    std::function<void(int)> m_LoadFunc;
    std::function<void()> m_BackFunc;
    std::vector<std::string> m_SaveFiles;
};
