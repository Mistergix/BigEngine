#include <iostream>
#include "core/game_time.h"
#include "Math/Matrix4.hpp"
#include "Math/Vector3.hpp"
#include "Math/Vector4.hpp"


void HandleInput();

int main() {

    Time time;
    auto isRunning = true;
    while(isRunning){
        HandleInput();
        /*LogicUpdate();
        PhysicsUpdate();
        Render();*/

        time.UpdateTime();
        if(time.CurrentTime() > 10.0){
            isRunning = false;
        }
    }
    return 0;
}

void HandleInput() {
    // Utiliser une lib ?
    // Stocker et dater les inputs
}
