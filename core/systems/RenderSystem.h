#pragma once


#include "entt/entity/registry.hpp"
#include "../components/GameObject.h"


class RenderSystem final
{
public:
    void update(entt::registry& registry, sf::RenderWindow& window);
};

