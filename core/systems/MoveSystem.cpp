#include "MoveSystem.h"
#include <loguru.hpp>

void MoveSystem::update(entt::registry& registry, sf::Window& window, float deltaTime)
{
    moveInputtables(registry, window, deltaTime);
}

void MoveSystem::moveInputtables(entt::registry& registry, sf::Window& window, float deltaTime)
{
    constexpr float accelerationValue = 550.f;
    auto view = registry.view<GameObject>();

    for(auto entity: view) {
        auto& gameObject = view.get<GameObject>(entity);
        auto& sprite = gameObject.getSprite();
        auto& textureRect = sprite.getTextureRect();

        // TODO Acceleration value is the same for all objects in the game now
        sprite.move(
                gameObject.getDirection().x * accelerationValue * deltaTime,
                gameObject.getDirection().y * accelerationValue * deltaTime);
        gameObject.position = sprite.getPosition();

        if (gameObject.isClamped())
        {
            // Do not allow movement beyond screen borders
            if(sprite.getPosition().x + textureRect.width > window.getSize().x)
                sprite.setPosition(window.getSize().x - textureRect.width, sprite.getPosition().y);
            if(sprite.getPosition().x < 0)
                sprite.setPosition(0, sprite.getPosition().y);

            if(sprite.getPosition().y + textureRect.height > window.getSize().y)
                sprite.setPosition(sprite.getPosition().x, window.getSize().y - textureRect.height);
            if(sprite.getPosition().y < 0)
                sprite.setPosition(sprite.getPosition().x, 0);
        }
        else
        {
            // Cleanup objects that go beyond the screen
            bool isBeyondScreenX = sprite.getPosition().x + textureRect.width > window.getSize().x || sprite.getPosition().x < 0;
            bool isBeyondScreenY = sprite.getPosition().y + textureRect.height > window.getSize().y || sprite.getPosition().y < 0;
            if (isBeyondScreenX || isBeyondScreenY)
            {
                
            }
        }
    }

    // Check for collisions
    auto colliderView = registry.view<Collider, GameObject>(entt::exclude<IInputtable>);
    for (auto entity: colliderView)
    {
        auto colliderObj = view.get<GameObject>(entity);

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