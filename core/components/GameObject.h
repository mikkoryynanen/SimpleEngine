#pragma once

#include "../entities/Entity.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "IDamageable.hpp"
#include "entt/entity/registry.hpp"

struct GameObject final : public Entity, IDamageable
{
private:
    sf::Sprite sprite;
    sf::Vector2i direction;

public:
    GameObject(sf::Color color, sf::Vector2f initialPosition);
    ~GameObject();

    sf::Sprite& getSprite() { return sprite; }

    sf::Vector2i getDirection() const { return direction; }
    void setDirection(const sf::Vector2i newDirection) { direction = newDirection; }

    bool takeDamage(int damage) override;
};