#include "GameObject.h"
#include "loguru.hpp"

GameObject::~GameObject()
{
}

GameObject::GameObject(sf::Color color, sf::Vector2f initialPosition)
{
    // TODO Build proper texture loader
    sf::Texture texture;
    texture.loadFromFile("resources/player.png");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture
            .getSize().y));
    sprite.setColor(color);
    sprite.setPosition(initialPosition);
}

void GameObject::takeDamage(int damage)
{
    reduceHealth(damage);
    if (getHealth())
    {
        LOG_F(INFO, "%s destroyed", name.c_str());
        flags.setFlag(QUEUE_FOR_DESTROY);
    }
}
