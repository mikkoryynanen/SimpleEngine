#pragma once

#include "entt/entity/registry.hpp"
#include "SFML/System/Vector2.hpp"

class Player final
{
public:
    Player(entt::registry& registry, const sf::Vector2f& initialPosition);

};