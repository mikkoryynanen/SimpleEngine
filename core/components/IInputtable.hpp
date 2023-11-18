//
// Created by Mikko Ryynänen on 16.11.2023.
//

#pragma once

enum Directions { None, Up, Down, Left, Right };

struct IInputtable final
{

private:
    sf::Vector2i inputVector;
    std::unordered_map<sf::Keyboard::Key, Directions> mappedKeys = {
            {sf::Keyboard::Unknown, None},
            {sf::Keyboard::W, Up},
            {sf::Keyboard::S, Down},
            {sf::Keyboard::A, Left},
            {sf::Keyboard::D, Right}
    };

public:

    const sf::Vector2i& getInputVector() const { return inputVector;  }
    void setInputVector(sf::Vector2i newVector)
    {
        inputVector = newVector;
    }
    sf::Keyboard::Key getBoundKey(const Directions& direction)
    {
        for (const auto& pair : mappedKeys)
        {
            auto f = pair.first;
            auto s = pair.second;
            if (pair.second == direction)
                return pair.first;
        }
        return sf::Keyboard::Unknown;
    }
};
