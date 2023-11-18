#include <iostream>
#include "MoveSystem.h"
#include "../entities/Collider.hpp"

void MoveSystem::update(entt::registry& registry, float deltaTime, sf::Window& window)
{
    constexpr float accelerationValue = 550.f;

    auto view = registry.view<IInputtable, GameObject>();
    std::vector<GameObject*> inputGameObjects;

    // TODO We currently only have one player, but reconsider adding this logic to a loop if we have more than one player

    for(auto entity: view) {
        auto& gameObject = view.get<GameObject>(entity);
        auto& inputtable = view.get<IInputtable>(entity);
        auto& sprite = gameObject.getSprite();
        auto& textureRect = sprite.getTextureRect();

        inputGameObjects.push_back(&gameObject);

//        std::cout << inputVector.x << inputVector.y << std::endl;

        sprite.move(
                inputtable.getInputVector().x * accelerationValue * deltaTime,
                inputtable.getInputVector().y * accelerationValue * deltaTime);

        // Clamp movement
        if(sprite.getPosition().x + textureRect.width > window.getSize().x)
            sprite.setPosition(window.getSize().x - textureRect.width, sprite.getPosition().y);
        if(sprite.getPosition().x < 0)
            sprite.setPosition(0, sprite.getPosition().y);

        if(sprite.getPosition().y + textureRect.height > window.getSize().y)
            sprite.setPosition(sprite.getPosition().x, window.getSize().y - textureRect.height);
        if(sprite.getPosition().y < 0)
            sprite.setPosition(sprite.getPosition().x, 0);
    }

    // Check for collisions
    auto colliderView = registry.view<Collider, GameObject>(entt::exclude<IInputtable>);
    for (auto entity: colliderView)
    {
        auto& colliderObj = view.get<GameObject>(entity);

        // Check if this object collides with anything
        for (auto& inputGameObject : inputGameObjects)
        {
            auto objectBounds = inputGameObject->getSprite().getGlobalBounds();
            auto otherColliderBounds = colliderObj.getSprite().getGlobalBounds();

            // TODO this intersection can occur when inside the object
            if (objectBounds.intersects(otherColliderBounds))
            {
//                std::cout << "HIT\n";
//                inputGameObject->getSprite().setColor(sf::Color::Red);
            }
        }
    }
}
