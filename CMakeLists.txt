cmake_minimum_required(VERSION 3.24)
project(simple_engine)

set(CMAKE_CXX_STANDARD 17)

############################################################
# EnTT from homebrew
include(FetchContent)
FetchContent_Declare(EnTT
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        )
FetchContent_MakeAvailable(EnTT)
############################################################

############################################################
# SFML
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
############################################################

add_executable(${PROJECT_NAME}
        main.cpp core/Engine.cpp core/Engine.h core/entities/Entity.cpp core/entities/Entity.h core/components/GameObject.cpp core/components/GameObject.h core/systems/MoveSystem.cpp core/systems/MoveSystem.h core/utils/ConfigReader.hpp core/systems/RenderSystem.cpp core/systems/RenderSystem.h core/entities/Player.hpp core/entities/Player.cpp core/state/State.cpp core/state/State.hpp core/state/StateMachine.cpp core/state/StateMachine.hpp core/state/PlayState.hpp core/state/PlayState.cpp core/state/IntroState.hpp
        core/components/IInputable.hpp
        core/entities/TestObject.hpp
        core/entities/TestObject.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics EnTT)

