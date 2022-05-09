cmake_minimum_required(VERSION 3.21)
project(Big_Engine)

set(CMAKE_CXX_STANDARD 17)

add_executable(Big_Engine main.cpp core/game_time.cpp core/game_time.h Math/Vector4.hpp Math/Vector4.cpp Math/Vector3.hpp Math/Vector3.cpp Math/Matrix4.hpp Math/Matrix4.cpp "core/Entity.hpp" "core/Entity.cpp" core/object.cpp core/object.h core/game_object.cpp core/game_object.h core/component.cpp core/component.h core/components/transform.cpp core/components/transform.h json.hpp scenes/scene.cpp scenes/scene.h)
