#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>


class MoveSystem
{
private:
    sf::Vector2i inputVector;

public:
    void update(entt::registry&  registry, float deltaTime, sf::Window &window);

    inline void onKeyUp() { inputVector.y = 1; }
    inline void onKeyDown() { inputVector.y = -1; }
    inline void onKeyLeft() { inputVector.x = 1; }
    inline void onKeyRight() { inputVector.x = -1; }
    inline void onNoInput() { inputVector.y = 0; inputVector.x = 0; }

    const sf::Vector2i getInputVector() const { return inputVector; }
};