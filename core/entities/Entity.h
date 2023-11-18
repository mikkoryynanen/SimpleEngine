#pragma once

#include <SFML/Graphics.hpp>
#include "../types/ObjectFlags.hpp"

struct Entity
{
public:
    Flags flags;
    sf::Vector2f position;

    Entity();
    ~Entity();
};
