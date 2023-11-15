#pragma once

#include "../entities/Entity.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

struct GameObject : public Entity
{
private:
    sf::Sprite sprite;

public:
    GameObject(float radius, sf::Color color, sf::Vector2f initialPosition);
    ~GameObject();

    inline sf::Sprite& getSprite() { return sprite; }

};