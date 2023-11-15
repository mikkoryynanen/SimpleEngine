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

    bool isRunning = false;

public:
    Engine();
    ~Engine();

    bool start();

    inline void stop() { isRunning = false; }
    inline sf::RenderWindow& getWindow() { return window; }
};