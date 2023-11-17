//
// Created by Mikko Ryynänen on 17.11.2023.
//

#include "CollisionSystem.hpp"
#include "../entities/Collider.hpp"
#include "../components/GameObject.h"

void CollisionSystem::update(entt::registry& registry, sf::Window& window)
{
    auto view = registry.view<Collider, GameObject>();
    std::vector<const sf::Rect<int>> list;

    for(auto entity: view)
    {
        auto& gameObject = view.get<GameObject>(entity);
        auto& rect = gameObject.getSprite().getTextureRect();
        // TODO These are copies
        list.push_back(rect);
    }
}
