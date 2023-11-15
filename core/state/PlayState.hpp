#pragma once

#include <iostream>

#include <entt/entt.hpp>

#include "../components/GameObject.h"
#include "SFML/Graphics/Color.hpp"
#include "../components/Player.hpp"
#include "../events/NoInput.hpp"
#include "../events/KeyDown.hpp"
#include "../events/KeyUp.hpp"
#include "../events/KeyLeft.hpp"
#include "../events/KeyRight.hpp"

#include "../systems/MoveSystem.h"
#include "../systems/GameTimeSystem.hpp"
#include "../systems/RenderSystem.h"

#include "State.hpp"


class PlayState final : public State
{
private:
    entt::registry registry;
    entt::dispatcher dispatcher;

    GameTimeSystem timeSystem;
    MoveSystem moveSystem;
    RenderSystem renderSystem;

public:
    PlayState(sf::RenderWindow& window) : State(window) { };

    void update() override;
};