#include "PlayState.hpp"
#include "../entities/TestObject.hpp"


void PlayState::update()
{
    // Player works as the container for components
    Player player(registry, sf::Vector2f { 400,300 });
    TestObject testObject(registry, sf::Vector2f { 200, 150});

    sf::Event event = {};
    while (isRunning)
    {
        timeSystem.update();

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    isRunning = false;
                    window.close();
                    break;
            }
        }

        moveSystem.update(registry, timeSystem.getDeltaTime(), window);
        renderSystem.update(registry, window);
    }
}
