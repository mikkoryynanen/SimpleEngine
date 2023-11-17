//
// Created by Mikko Ryynänen on 17.11.2023.
//

#pragma once

#include "SFML/Window.hpp"
#include "entt/entity/registry.hpp"

class CollisionSystem
{
public:
    void update(entt::registry& registry, sf::Window &window);
};
