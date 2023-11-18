#pragma once

#include <iostream> // TODO FOR DEBUGGING
#include <cmath>

#include <SFML/Graphics.hpp>

#include "utils/ConfigReader.hpp"
#include "state/StateMachine.hpp"

#include "state/PlayState.hpp"

class Engine {

private:
    sf::RenderWindow window;
    StateMachine stateMachine;

public:
    Engine();

    bool start();
    sf::RenderWindow& getWindow() { return window; }
};