#pragma once

#include "SFML/Graphics/RenderWindow.hpp"

class State {
protected:
    sf::RenderWindow& window;
    bool isRunning = false;


public:
    State(sf::RenderWindow& window) : window(window)
    {
        isRunning = true;
    }

    virtual void update() = 0;

    void quit() { isRunning = false; }
};
