//
// Created by Mikko Ryynänen on 17.11.2023.
//

#include "AiSystem.hpp"
#include "../entities/AIBasicMovement.hpp"

void AISystem::update(entt::registry& registry, sf::Window& window, float deltaTime)
{
    constexpr float MOVEMENT_SPEED = 25.f;
    constexpr float AMPLITUDE = 1.f;
    constexpr float FREQUENCY = .05f;
    constexpr float STEP_SIZE = .05f;

    auto view = registry.view<AIBasicMovement, GameObject>();
    for (auto entity : view)
    {
        auto& gameObject = view.get<GameObject>(entity);
        auto& sprite = gameObject.getSprite();

        float x = AMPLITUDE * std::sin(FREQUENCY * sprite.getPosition().y);
        x += STEP_SIZE * deltaTime;

        sprite.move(sf::Vector2f
        {
            x,
            1.f * MOVEMENT_SPEED * deltaTime
        });
    }
}
