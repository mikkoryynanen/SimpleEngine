//
// Created by Mikko Ryynänen on 16.11.2023.
//

#include "TestObject.hpp"
#include "../components/GameObject.h"
#include "AIBasicMovement.hpp"

TestObject::TestObject(entt::registry& registry, const sf::Vector2f& initialPosition)
{
    const auto testObj = registry.create();
    registry.emplace<GameObject>(testObj, 50.f, sf::Color::Green, initialPosition);
    registry.emplace<AIBasicMovement>(testObj);

    auto& go = registry.get<GameObject>(testObj);
    auto& sprite = go.getSprite();
    sprite.setPosition(initialPosition);
}
