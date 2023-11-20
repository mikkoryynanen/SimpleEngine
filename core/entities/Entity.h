#pragma once

#include <SFML/Graphics.hpp>
#include "../types/ObjectFlags.hpp"
#include "../types/CollisionLayer.hpp"

struct Entity
{
public:
    std::string name;

    // Flags indicating what features does our object have
    // For example, Should this object be destroyed when it's outside of screen
    Flags<ObjectFlags> flags;

    // Flags indicating what layers can we collide with
    Flags<CollisionLayer> collisionLayers;

    sf::Vector2f position;

    Entity();
    ~Entity();
};
