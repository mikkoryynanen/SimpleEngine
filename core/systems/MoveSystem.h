#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include "../entities/Player.hpp"
#include "../components/GameObject.h"
#include "../components/IInputtable.hpp"

class MoveSystem final
{

public:
    void update(entt::registry& registry, float deltaTime, sf::Window& window);
};