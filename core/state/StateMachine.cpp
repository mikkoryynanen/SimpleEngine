#include "StateMachine.hpp"

void StateMachine::nextState()
{
    states.top()->quit();
    if(!states.empty())
    {
        states.pop();
    }

    states.top();
}

void StateMachine::previousState()
{
}

void StateMachine::update()
{
    states.top()->update();
}

void StateMachine::build(std::unique_ptr<State> newState)
{
    states.push(std::move(newState));
}
