// GamePaused_State.h
#pragma once
#include "GameState.h"
#include <memory>

class EngGUI;
class InputManager; // hypothetical

class GamePaused_State : public GameState
{
public:
    GamePaused_State(std::shared_ptr<EngGUI> gui, std::shared_ptr<InputManager> input);
    void Enter() override;
    void Exit() override;
    void HandleInput() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    std::shared_ptr<EngGUI> m_GUI;
    std::shared_ptr<InputManager> m_Input;
    bool m_ShowPauseMenu = true;
};
