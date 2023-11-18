#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include "../entities/Player.hpp"
#include "../components/GameObject.h"
#include "../components/IInputtable.hpp"

class MoveSystem final
{
private:
    std::vector<GameObject*> inputGameObjects;

    void moveInputtables(entt::registry& registry, sf::Window& window, float deltaTime);

public:
    void update(entt::registry& registry, sf::Window& window, float deltaTime);
};