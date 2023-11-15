#include "PlayState.hpp"


void PlayState::update()
{
    //    if(!networkSystem.connect())
//    {
//        isRunning = false;
//        return false;
//    }

    // Create entities
    const auto player = registry.create();

    // Assign component date to player entity
    registry.emplace<GameObject>(player, 50.f, sf::Color::Green, sf::Vector2f(300, 400));
    registry.emplace<Player>(player);
//    registry.emplace<Networked>(player);

    // Attaching input to dispatcher
    dispatcher.sink<NoInput>().connect<&MoveSystem::onNoInput>(moveSystem);
    dispatcher.sink<KeyUp>().connect<&MoveSystem::onKeyUp>(moveSystem);
    dispatcher.sink<KeyDown>().connect<&MoveSystem::onKeyDown>(moveSystem);
    dispatcher.sink<KeyLeft>().connect<&MoveSystem::onKeyLeft>(moveSystem);
    dispatcher.sink<KeyRight>().connect<&MoveSystem::onKeyRight>(moveSystem);

//    networkSystem.connect();

    // Events Loop
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

                    // TODO Might not be the best place to put this
                    // Other input is fetched in real-time, this happens after a delay
                    // Figure out from documentation later, good now for
                case sf::Event::KeyReleased:
                    dispatcher.trigger<NoInput>();
                    break;

                default:
                    break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            dispatcher.trigger<KeyUp>();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            dispatcher.trigger<KeyDown>();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)  || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            dispatcher.trigger<KeyLeft>();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)  || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            dispatcher.trigger<KeyRight>();

        // Render loop
        window.clear();

        moveSystem.update(registry, timeSystem.getDeltaTime(), this->window);
        renderSystem.update(registry, window, timeSystem.getTime());
//        networkSystem.update(registry, timeSystem.getTime(), moveSystem.getInputVector());

        window.display();
    }

}
