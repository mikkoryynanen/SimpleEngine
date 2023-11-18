#include "Player.hpp"
#include <loguru.hpp>

Player::Player(entt::registry& registry, const sf::Vector2f& initialPosition)
        : registryRef(registry)
{
    // Generate the registry for Player and emplace all the components to it
    entity = registry.create();

    registry.emplace<GameObject>(entity, sf::Color::White, initialPosition);

    // TODO Get these value from the config reader
//    ConfigReader configReader;
    registry.emplace<IInputtable>(entity);

    registry.emplace<Collider>(entity);

    auto& go = registry.get<GameObject>(entity);
    go.flags.setFlag(CLAMP_FOR_SCREEN);

    auto& sprite = go.getSprite();
    sprite.setPosition(initialPosition);
}

void Player::update(float deltaTime)
{
    fireTimer += deltaTime;
    if (fireTimer >= fireRate)
    {
        auto& go = registryRef.get<GameObject>(entity);
//        LOG_F(INFO, "FIRING at pos %f %f", position.x, position.y);
        auto projectile = new Projectile(registryRef, go.position);
        fireTimer = 0;
    }
}
