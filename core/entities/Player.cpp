#include "Player.hpp"
#include "../components/GameObject.h"
#include "../components/IInputtable.hpp"
#include "Collider.hpp"
#include "../utils/ConfigReader.hpp"

Player::Player(entt::registry &registry, const sf::Vector2f &initialPosition)
{
    // Generate the registry for Player and emplace all the components to it
    const auto player = registry.create();

    registry.emplace<GameObject>(player, 50.f, sf::Color::Green, sf::Vector2f(300, 400));

    // TODO Get these value from the config reader
//    ConfigReader configReader;
    registry.emplace<IInputtable>(player);

    registry.emplace<Collider>(player);

    auto& go = registry.get<GameObject>(player);
    auto& sprite = go.getSprite();
    sprite.setPosition(initialPosition);
}