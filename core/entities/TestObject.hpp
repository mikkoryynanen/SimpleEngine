//
// Created by Mikko Ryynänen on 16.11.2023.
//

#pragma once

#include "entt/entity/registry.hpp"
#include "SFML/Graphics/Texture.hpp"

class TestObject final {
public:
    TestObject(entt::registry& registry, const sf::Vector2f& initialPosition);
};
