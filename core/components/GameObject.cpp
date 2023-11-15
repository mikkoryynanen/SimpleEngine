#include "GameObject.h"

GameObject::~GameObject()
{

}

GameObject::GameObject(float radius, sf::Color color, sf::Vector2f initialPosition)
{
    // TODO Build proper texture loader
    sf::Texture texture;
    texture.loadFromFile("resources/player.png");

    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture
    .getSize().y));
//    this->sprite.setColor(sf::Color(255, 255, 255, 200));
    this->sprite.setPosition(0, 0);
}
