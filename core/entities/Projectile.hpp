//
// Created by Mikko Ryynänen on 18.11.2023.
//

#pragma once

#include "entt/entity/registry.hpp"
#include "../components/GameObject.h"

class Projectile
{
public:
    Projectile(entt::registry& registry, const sf::Vector2f& initialPosition)
    {
        const auto projectile = registry.create();
        registry.emplace<GameObject>(projectile, sf::Color::Red, initialPosition);
        auto& go = registry.get<GameObject>(projectile);
        go.setDirection(sf::Vector2i { 0, -1});
        go.setClamped(false);
    }
};