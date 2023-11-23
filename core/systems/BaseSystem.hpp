//
// Created by Mikko Ryynänen on 22.11.2023.
//

#pragma once

#include "entt/entity/registry.hpp"

class BaseSystem
{
public:
    explicit BaseSystem(entt::registry& registry) : m_registry(registry) {}

protected:
    entt::registry& m_registry;

};
