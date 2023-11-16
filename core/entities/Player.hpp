#pragma once

#include "entt/entity/registry.hpp"
#include "SFML/System/Vector2.hpp"

struct Player
{
public:
    Player(entt::registry& registry, const sf::Vector2f& initialPosition);

};