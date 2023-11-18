//
// Created by Mikko Ryynänen on 17.11.2023.
//

#include "InputSystem.hpp"
#include "../components/GameObject.h"
#include "../components/IInputtable.hpp"

void InputSystem::update(entt::registry& registry, sf::Window& window)
{
    auto view = registry.view<IInputtable, GameObject>();

    // TODO We currently only have one player, but reconsider adding this logic to a loop if we have more than one player

    for(auto entity: view)
    {
        auto& gameObject = view.get<GameObject>(entity);
        auto& inputtable = view.get<IInputtable>(entity);

        // Movement
        sf::Vector2i inputVector;
        if (sf::Keyboard::isKeyPressed(inputtable.getBoundKey(Directions::Up)))
            inputVector.y = -1;
        else if (sf::Keyboard::isKeyPressed(inputtable.getBoundKey(Directions::Down)))
            inputVector.y = 1;
        else
            inputVector.y = 0;

        if (sf::Keyboard::isKeyPressed(inputtable.getBoundKey(Directions::Left)))
            inputVector.x = -1;
        else if (sf::Keyboard::isKeyPressed(inputtable.getBoundKey(Directions::Right)))
            inputVector.x = 1;
        else
            inputVector.x = 0;

        gameObject.setDirection(inputVector);
    }
}
