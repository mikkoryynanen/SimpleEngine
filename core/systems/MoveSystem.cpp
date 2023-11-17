#include <iostream>
#include "MoveSystem.h"
#include "../entities/Collider.hpp"

void MoveSystem::update(entt::registry& registry, float deltaTime, sf::Window& window)
{
    constexpr float accelerationValue = 550.f;

    auto view = registry.view<IInputable, GameObject>();
    std::vector<GameObject*> inputGameObjects;

    for(auto entity: view) {
        auto& gameObject = view.get<GameObject>(entity);
        auto& sprite = gameObject.getSprite();
        auto& textureRect = sprite.getTextureRect();

        inputGameObjects.push_back(&gameObject);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            inputVector.y = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            inputVector.y = 1;
        else
            inputVector.y = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            inputVector.x = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            inputVector.x = 1;
        else
            inputVector.x = 0;

//        std::cout << inputVector.x << inputVector.y << std::endl;

        sprite.move(
                inputVector.x * accelerationValue * deltaTime,
                inputVector.y * accelerationValue * deltaTime);

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
    auto colliderView = registry.view<Collider, GameObject>(entt::exclude<IInputable>);
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
