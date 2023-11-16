#pragma once

#include "../entities/Entity.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

struct GameObject final : public Entity
{
private:
    sf::Sprite sprite;

public:
    GameObject(float radius, sf::Color color, sf::Vector2f initialPosition);
    ~GameObject();

    sf::Sprite& getSprite() { return sprite; }

};