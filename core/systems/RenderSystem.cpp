#include "RenderSystem.h"
#include "loguru.hpp"

void RenderSystem::update(entt::registry &registry, sf::RenderWindow& window)
{
    window.clear();

    auto view = registry.view<GameObject>();
    for(auto entity: view) {
        auto& gameObject= view.get<GameObject>(entity);

        // TODO This could be moved to cleanup manager
        if (gameObject.flags.hasFlag(QUEUE_FOR_DESTROY))
        {
            LOG_F(INFO, "GameObject destroyed");
            registry.remove<GameObject>(entity);
            // TODO There is a bug where this causes all of the future objets to be destroyed as well
        }

        window.draw(gameObject.getSprite());
    }

    window.display();
}
