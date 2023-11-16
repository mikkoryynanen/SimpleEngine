#pragma once

#include "State.hpp"

#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>

class StateMachine {
private:
    std::stack<std::unique_ptr<State>> states;

public:
    void nextState();
    void previousState();

    void update();
    void build(std::unique_ptr<State> newState);
};

