#include "Player.hpp"
#include "../components/GameObject.h"
#include "../components/IInputable.hpp"
#include "Collider.hpp"

Player::Player(entt::registry &registry, const sf::Vector2f &initialPosition)
{
    // Generate the registry for Player and emplace all the components to it
    const auto player = registry.create();
    registry.emplace<GameObject>(player, 50.f, sf::Color::Green, sf::Vector2f(300, 400));
    registry.emplace<IInputable>(player);
    registry.emplace<Collider>(player);

    auto& go = registry.get<GameObject>(player);
    auto& sprite = go.getSprite();
    sprite.setPosition(initialPosition);
}
