#pragma once

#include "../entities/Entity.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

struct GameObject final : public Entity
{
private:
    sf::Sprite sprite;
    sf::Vector2i direction;
    bool clampToScreen = true;

public:
    GameObject(sf::Color color, sf::Vector2f initialPosition);
    ~GameObject();

    sf::Sprite& getSprite() { return sprite; }

    sf::Vector2i getDirection() const { return direction; }
    void setDirection(const sf::Vector2i newDirection) { direction = newDirection; }

    bool isClamped() const { return clampToScreen; }
    void setClamped(bool isClamped) { clampToScreen = isClamped; }
};