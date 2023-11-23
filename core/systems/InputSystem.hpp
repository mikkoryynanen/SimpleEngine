//
// Created by Mikko Ryynänen on 17.11.2023.
//

#pragma once


#include "entt/entity/registry.hpp"
#include "SFML/Window.hpp"

class InputSystem final {

public:

    void update(entt::registry& registry);

};
