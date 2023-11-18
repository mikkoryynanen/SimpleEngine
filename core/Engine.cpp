#include "Engine.h"
#include "state/IntroState.hpp"
#include <thread>

Engine::Engine()
{
    // Load config file
    // Pretty much everything depends on this,
    // make sure loading this is successful before moving any further
    ConfigReader configReader;
    window.create(sf::VideoMode(
            std::stoi(configReader.getValue("WindowWidth")),
            std::stoi(configReader.getValue("WindowWidth"))),
                  configReader.getValue("Title"));
    window.setFramerateLimit(std::stoi(configReader.getValue("MaxFramerate")));
}

bool Engine::start()
{
    // Build states, LIFO stack
    stateMachine.build(std::make_unique<PlayState>(getWindow()));
    stateMachine.build(std::make_unique<IntroState>(getWindow()));

    // TODO Example of how to use the state machine
    // 1. Start some state in the background(IntroState)
//    std::thread stateMachineThread([&](){
//        stateMachine.update();
//    });
//
//    // 2. Wait for a second
//    std::this_thread::sleep_for(std::chrono::seconds(5));
//    stateMachineThread.detach();

    // 3. And start new state by doing the following
    stateMachine.nextState();
    stateMachine.update();

    return false;
}