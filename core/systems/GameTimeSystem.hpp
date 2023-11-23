#pragma once

#include <SFML/System/Clock.hpp>

class GameTimeSystem final
{
public:
    void update() {
        deltaTime = clock.restart();
//        newTime = clock.getElapsedTime().asMilliseconds();
//        frameTime = newTime - currentTime;
//        currentTime = newTime;
//
//        accumulator += frameTime;
//
//        while (accumulator >= deltaTime)
//        {
//            accumulator -= deltaTime;
//            time += deltaTime;
//        }
    }

    double getTime() const { return time; }
    float getDeltaTime() const { return deltaTime.asSeconds(); }

private:
//    static constexpr double deltaTime = 1000. / 60.;
    sf::Time deltaTime;
    double time = 0.;
    double accumulator = 0.;
    sf::Clock clock;
    double currentTime = clock.getElapsedTime().asMilliseconds();
    double newTime = 0.;
    double frameTime = 0.;
};