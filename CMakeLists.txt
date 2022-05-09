cmake_minimum_required(VERSION 3.21)
project(Big_Engine)

set(CMAKE_CXX_STANDARD 17)

add_executable(Big_Engine main.cpp core/game_time.cpp core/game_time.h core/object.cpp core/object.h core/game_object.cpp core/game_object.h core/component.cpp core/component.h core/components/transform.cpp core/components/transform.h json.hpp scenes/scene.cpp scenes/scene.h)
