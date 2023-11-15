#include "MoveSystem.h"

// TODO This does not work when moved to header for some reason...
#include "../Engine.h"


void MoveSystem::update(entt::registry &registry, float deltaTime, sf::Window &window)
{
    const float accelerationValue = 450.f;

    auto view = registry.view<Player, GameObject>();

    for(auto entity: view) {
        auto& gameObject = view.get<GameObject>(entity);
        sf::Vector2f movement(0.0f, 0.0f);

        if(inputVector.x > 0)
            movement.x -= accelerationValue;
        if(inputVector.x < 0)
            movement.x += accelerationValue;
        if(inputVector.y > 0)
            movement.y -= accelerationValue;
        if(inputVector.y < 0)
            movement.y += accelerationValue;

        gameObject.getSprite().move(movement * deltaTime);
        auto textureSize = gameObject.getSprite().getTextureRect();

//        std::cout << gameObject.getSprite().getPosition().x << " of " << window.getSize().x << std::endl;
        std::cout << gameObject.getSprite().getPosition().y << " of " << window.getSize().y << std::endl;

        // Clamp movement
        if(gameObject.getSprite().getPosition().x + textureSize.width > window.getSize().x)
            gameObject.getSprite().setPosition(window.getSize().x - textureSize.width, gameObject.getSprite().getPosition().y);
        if(gameObject.getSprite().getPosition().x < 0)
            gameObject.getSprite().setPosition(0, gameObject.getSprite().getPosition().y);

        if(gameObject.getSprite().getPosition().y + textureSize.height > window.getSize().y)
            gameObject.getSprite().setPosition(gameObject.getSprite().getPosition().x, window.getSize().y - textureSize.height);
        if(gameObject.getSprite().getPosition().y < 0)
            gameObject.getSprite().setPosition(gameObject.getSprite().getPosition().x, 0);
    }
}