#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include "../entities/Player.hpp"
#include "../components/GameObject.h"
#include "../components/IInputable.hpp"

class MoveSystem
{
private:
    sf::Vector2i inputVector;

public:
    void update(entt::registry& registry, float deltaTime, sf::Window &window);

    const sf::Vector2i getInputVector() const { return inputVector; }
};