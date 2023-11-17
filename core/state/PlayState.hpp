#pragma once

#include <iostream>

#include <entt/entt.hpp>

#include "../components/GameObject.h"
#include "SFML/Graphics/Color.hpp"
#include "../entities/Player.hpp"

#include "../systems/MoveSystem.h"
#include "../systems/GameTimeSystem.hpp"
#include "../systems/RenderSystem.h"

#include "State.hpp"
#include "../systems/AiSystem.hpp"

class PlayState final : public State
{
private:
    entt::registry registry;

    GameTimeSystem timeSystem;
    MoveSystem moveSystem;
    RenderSystem renderSystem;
    AISystem aiSystem;

public:
    PlayState(sf::RenderWindow& window) : State(window) { };

    void update() override;
};