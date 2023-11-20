//
// Created by Mikko Ryynänen on 16.11.2023.
//

#include "TestObject.hpp"
#include "../components/GameObject.h"
#include "AIBasicMovement.hpp"
#include "Collider.hpp"

TestObject::TestObject(entt::registry& registry, const sf::Vector2f& initialPosition)
{
    const auto testObj = registry.create();
    registry.emplace<GameObject>(testObj, sf::Color::White, initialPosition);
    registry.emplace<AIBasicMovement>(testObj);
    registry.emplace<Collider>(testObj);

    auto& go = registry.get<GameObject>(testObj);
    go.name = "Enemy";
    go.collisionLayers.setFlag(PROJECTILE);
    go.collisionLayers.setFlag(ENEMY);
    auto& sprite = go.getSprite();
    sprite.setPosition(initialPosition);
}
