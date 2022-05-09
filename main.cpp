#include <iostream>
#include "core/game_time.h"
#include "core/object.h"
#include "core/game_object.h"
#include "core/components/transform.h"
#include "scenes/scene.h"
#include "editor/editor.h"


void HandleInput();

int main() {
    Editor editor;


    std::string scenePath = "Assets/Scenes/SceneTest.scene";
    Scene scene(scenePath);
    std::cout << scene.name() << std::endl;

    /*
    Time time;
    auto isRunning = true;
    while(isRunning){
        HandleInput();
        LogicUpdate();
        PhysicsUpdate();
        Render();

        time.UpdateTime();
        if(time.CurrentTime() > 10.0){
            isRunning = false;
        }
    }*/
    return 0;
}

void HandleInput() {
    // Utiliser une lib ?
    // Stocker et dater les inputs
}
