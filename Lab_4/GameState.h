// GameState.h
#pragma once
#include <memory>

class GameState
{
public:
    virtual ~GameState() = default;
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    virtual void HandleInput() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;
};
