#include "PlayState.hpp"
#include "../entities/TestObject.hpp"


void PlayState::update()
{
    // Create state/scenes objects
    Player player(registry, sf::Vector2f { 400,300 });
    TestObject testObject(registry, sf::Vector2f { 350, 0});
    TestObject testObject1(registry, sf::Vector2f { 150, 0});
    TestObject testObject2(registry, sf::Vector2f { 50, 0});

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
        aiSystem.update(registry, window, timeSystem.getDeltaTime());
    }
}
