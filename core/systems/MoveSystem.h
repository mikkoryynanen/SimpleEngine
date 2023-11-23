#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include "../entities/Player.hpp"
#include "../components/GameObject.h"
#include "../components/IInputtable.hpp"
#include "BaseSystem.hpp"

class MoveSystem final : public BaseSystem
{
public:
    MoveSystem(entt::registry& registry, sf::Window& window);

    void update(float deltaTime);

private:
    sf::Window* m_window;
    std::vector<GameObject*> m_inputGameObjects;

    void moveInputtables(float deltaTime);
};