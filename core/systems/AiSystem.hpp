//
// Created by Mikko Ryynänen on 17.11.2023.
//

#pragma once

#include "SFML/Window.hpp"
#include "entt/entity/registry.hpp"
#include "MoveSystem.h"

class AISystem {
public:
    void update(entt::registry& registry, sf::Window& window, float deltaTime);
};
