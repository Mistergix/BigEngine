cmake_minimum_required(VERSION 3.21)
project(Big_Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Bin)

LINK_DIRECTORIES(./Lib)
INCLUDE_DIRECTORIES(./ThirdParty)

LINK_LIBRARIES(glfw3 glew32 opengl32)

add_executable(Big_Engine main.cpp core/game_time.cpp core/game_time.h core/object.cpp core/object.h core/game_object.cpp core/game_object.h core/component.cpp core/component.h core/components/transform.cpp core/components/transform.h utils/json.hpp scenes/scene.cpp scenes/scene.h utils/prefab_utils.cpp utils/prefab_utils.h utils/json_reader.cpp utils/json_reader.h editor/assets_importer.cpp editor/assets_importer.h editor/editor.cpp editor/editor.h core/config/project_settings.cpp core/config/project_settings.h Math/Vector4.hpp Math/Vector4.cpp Math/Vector3.hpp Math/Vector3.cpp Math/Matrix4.hpp Math/Matrix4.cpp core/components/camera.cpp core/components/camera.h core/game.cpp core/game.h core/components/renderer.cpp core/components/renderer.h core/components/mesh.cpp core/components/mesh.h Math/primitives.cpp Math/primitives.h core/components/rigidbody.cpp core/components/rigidbody.h)
