#pragma once

#include "State.hpp"

class IntroState final : public State
{
public:
    IntroState(sf::RenderWindow& window) : State(window) { };

    void update() override;
};

void IntroState::update()
{
    while (isRunning)
    {
        std::cout << "Running IntroState..." << std::endl;
    }
}
