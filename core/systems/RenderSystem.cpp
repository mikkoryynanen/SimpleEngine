#include "RenderSystem.h"



void RenderSystem::update(entt::registry &registry, sf::RenderWindow& window)
{
    window.clear();

    auto myShapeView = registry.view<GameObject>();
    for(auto entity: myShapeView) {
        auto gameObject = myShapeView.get<GameObject>(entity);
        window.draw(gameObject.getSprite());
    }

    window.display();
}
