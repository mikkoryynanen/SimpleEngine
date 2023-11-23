#include "PlayState.hpp"
#include "../entities/TestObject.hpp"
#include "loguru.hpp"

void PlayState::update()
{
    // Create state/scenes objects
    Player player(registry, sf::Vector2f{400, 300});
    std::vector<TestObject> enemies;
    for (int i = 0; i < 10; ++i) {
        TestObject testObject(registry, sf::Vector2f { 75.f * i, 0});
        enemies.push_back(testObject);
    }

    while (isRunning)
    {
        timeSystem.update();

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                isRunning = false;
                window.close();
            }
        }

        player.update(timeSystem.getDeltaTime());

        inputSystem.update(registry);
        moveSystem.update(timeSystem.getDeltaTime());
        renderSystem.update(registry, window);
        aiSystem.update(registry, window, timeSystem.getDeltaTime());
    }
}
