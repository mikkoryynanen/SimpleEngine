#pragma once

#include <SFMl/Graphics.hpp>

#include "entt/entity/registry.hpp"
#include "../components/GameObject.h"


class RenderSystem
{
public:
    void update(entt::registry& registry, sf::RenderWindow& window);
};

