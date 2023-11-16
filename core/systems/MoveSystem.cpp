#include <iostream>
#include "MoveSystem.h"


void MoveSystem::update(entt::registry& registry, float deltaTime, sf::Window& window)
{
    constexpr float accelerationValue = 550.f;

    auto view = registry.view<IInputable, GameObject>();

    for(auto entity: view) {
        auto& gameObject = view.get<GameObject>(entity);
        auto& sprite = gameObject.getSprite();
        sf::Vector2f movement(0.0f, 0.0f);

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
        auto textureSize = sprite.getTextureRect();
        if(sprite.getPosition().x + textureSize.width > window.getSize().x)
            sprite.setPosition(window.getSize().x - textureSize.width, sprite.getPosition().y);
        if(sprite.getPosition().x < 0)
            sprite.setPosition(0, sprite.getPosition().y);

        if(sprite.getPosition().y + textureSize.height > window.getSize().y)
            sprite.setPosition(sprite.getPosition().x, window.getSize().y - textureSize.height);
        if(sprite.getPosition().y < 0)
            sprite.setPosition(sprite.getPosition().x, 0);
    }
}