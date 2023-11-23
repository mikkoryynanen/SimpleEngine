#include "MoveSystem.h"
#include <loguru.hpp>

MoveSystem::MoveSystem(entt::registry& registry, sf::Window& window)
        : BaseSystem(registry)
{
    m_window = &window;
}

void MoveSystem::update(float deltaTime)
{
    moveInputtables(deltaTime);
}

void MoveSystem::moveInputtables(float deltaTime)
{
    constexpr float accelerationValue = 550.f;
    auto view = m_registry.view<GameObject>();

    for(const auto& entity: view) {
        auto& gameObject = view.get<GameObject>(entity);
        auto& sprite = gameObject.getSprite();
        auto& textureRect = sprite.getTextureRect();

        // TODO Acceleration value is the same for all objects in the game now
        sprite.move(
                gameObject.getDirection().x * accelerationValue * deltaTime,
                gameObject.getDirection().y * accelerationValue * deltaTime);
        gameObject.position = sprite.getPosition();

        if (gameObject.flags.hasFlag(CLAMP_FOR_SCREEN))
        {
            // Do not allow movement beyond screen borders
            if(sprite.getPosition().x + textureRect.width > m_window->getSize().x)
                sprite.setPosition(m_window->getSize().x - textureRect.width, sprite.getPosition().y);
            if(sprite.getPosition().x < 0)
                sprite.setPosition(0, sprite.getPosition().y);

            if(sprite.getPosition().y + textureRect.height > m_window->getSize().y)
                sprite.setPosition(sprite.getPosition().x, m_window->getSize().y - textureRect.height);
            if(sprite.getPosition().y < 0)
                sprite.setPosition(sprite.getPosition().x, 0);
        }
        else if (gameObject.flags.hasFlag(DESTROY_OUTSIDE_SCREEN))
        {
            // Cleanup objects that go beyond the screen
            bool isBeyondScreenX = sprite.getPosition().x + textureRect.width > m_window->getSize().x || sprite.getPosition().x < -textureRect.width;
            bool isBeyondScreenY = sprite.getPosition().y + textureRect.height > m_window->getSize().y || sprite.getPosition().y < -textureRect.height;
            if (isBeyondScreenX || isBeyondScreenY)
            {
                gameObject.flags.setFlag(QUEUE_FOR_DESTROY);
            }
        }
    }

    // TODO Move this to collision system?
    // Check for collisions
    auto colliderView= m_registry.view<Collider, GameObject>();
    for (auto entity: colliderView)
    {
        auto colliderObj = colliderView.get<GameObject>(entity);
        auto colliderObjBounds= colliderObj.getSprite().getGlobalBounds();

        for (auto otherEntity : colliderView)
        {
            auto otherObj = colliderView.get<GameObject>(otherEntity);
            // TODO could have a bit better check here
            if (colliderObj.name == otherObj.name)
            {
                continue;
            }

            // Check for collision layers
            if ((colliderObj.collisionLayers.getFlags() & otherObj.collisionLayers.getFlags()) == 0)
            {
                continue;
            }

            auto otherBounds = otherObj.getSprite().getGlobalBounds();
            if (colliderObjBounds.intersects(otherBounds))
            {
                // TODO This logic could be somewhere else
                if (otherObj.takeDamage(100))
                {
                    m_registry.remove<GameObject>(otherEntity);
                }

                if (colliderObj.takeDamage(100))
                {
                    m_registry.remove<GameObject>(entity);
                }
            }
        }

        // Check if input objects have collided with anything
        for (auto& inputGameObject : m_inputGameObjects)
        {
            auto inputObjectBounds = inputGameObject->getSprite().getGlobalBounds();
            // TODO this intersection can occur when inside the object
            if (inputObjectBounds.intersects(colliderObjBounds))
            {
                LOG_F(INFO, "HIT");
//                colliderObj.flags.setFlag(QUEUE_FOR_DESTROY);
//                inputGameObject->getSprite().setColor(sf::Color::Red);
            }
        }
    }
}