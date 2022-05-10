//
// Created by nicol on 10/05/2022.
//

#include "game.h"
#include "../scenes/scene.h"

void HandleInput() {
    // Utiliser une lib ?
    // Stocker et dater les inputs
}

void Game::Run() {
    std::string scenePath = "Assets/Scenes/SceneTest.scene";
    Scene scene(scenePath);
    std::cout << scene.name() << std::endl;

    auto gos = FIND_OBJECTS_OF_TYPE(Transform);
    auto gosWithTag = GameObject::FindObjectsWithTag("Bibi");

    std::cout << gos->size() << " of type Transform" <<  std::endl;

    std::cout << gosWithTag->size() << " with tag bibi" <<  std::endl;



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
}
