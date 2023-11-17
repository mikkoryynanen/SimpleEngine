#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include "../entities/Player.hpp"
#include "../components/GameObject.h"
#include "../components/IInputable.hpp"

class MoveSystem final
{
private:
    sf::Vector2i inputVector;

public:
    void update(entt::registry& registry, float deltaTime, sf::Window& window);
};