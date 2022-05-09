#include <iostream>
#include "core/game_time.h"
#include "core/object.h"
#include "core/game_object.h"
#include "core/components/transform.h"
#include "scenes/scene.h"


void HandleInput();

int main() {
    std::string scenePath = "Assets/Scenes/SceneTest.json";
    Scene scene(scenePath);
    std::cout << scene.name() << std::endl;

    /*
    GameObject go("Test GO");
    std::cout << go.name() << std::endl;
    if(go.transform()){
        std::cout << "HAS TRANSFORM" << std::endl;
    }*/
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
