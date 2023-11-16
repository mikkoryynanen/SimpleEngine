#include "core/Engine.h"

void modifyCurrentWorkingDirectory()
{
    while (!std::filesystem::exists("resources"))
    {
        std::filesystem::current_path(std::filesystem::current_path().parent_path());
    }
    auto cwd = std::filesystem::current_path();
}

int main()
{
    modifyCurrentWorkingDirectory();

    Engine engine;
    engine.start();

    return 0;
}