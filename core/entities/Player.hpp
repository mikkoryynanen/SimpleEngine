#pragma once

#include "entt/entity/registry.hpp"
#include "SFML/System/Vector2.hpp"
#include "../components/GameObject.h"
#include "../components/IInputtable.hpp"
#include "Collider.hpp"
#include "Projectile.hpp"

class Player final
{
public:
    Player(entt::registry& registry, const sf::Vector2f& initialPosition);

    void update(float deltaTime);

private:
    // TODO Might have to figure out a better place for this, this pattern should reoccur when we are implementing firing enemies
    entt::registry& registryRef;
    entt::entity entity;

    float fireTimer = 0.f;
    float fireRate = .75f;

};