//
// Created by nicol on 10/05/2022.
//

#include "game.h"
#include "../scenes/scene.h"

void Game::Run() {
    std::string scenePath = "Assets/Scenes/SceneTest.scene";
    Scene scene(scenePath);
    std::cout << scene.name() << std::endl;
    auto gos = FIND_OBJECTS_OF_TYPE(Transform);
    auto gosWithTag = GameObject::FindObjectsWithTag("Bibi");
    std::cout << gos->size() << " of type Transform" <<  std::endl;
    std::cout << gosWithTag->size() << " with tag bibi" <<  std::endl;
    //TODO refactor the timers in separate modules
    _updateTimer = new Timer();
    _updateTimer->reset();
    _physicsTimer = new Timer();
    _physicsTimer->reset();

    _continueRunning = true;

    double accumulatedTimeUpdate = 0.0;
    int nbLoopsUpdate = 0;
    double accumulatedTimePhysics = 0.0;
    int nbLoopsPhysics = 0;

    const int updateFPSTarget = 60;
    const int physicsFPSTarget = 100;

    _dtUpdate = 1000.0 / updateFPSTarget;
    _maxSkipFramesUpdate = 10;
    _dtPhysics = 1000.0 / physicsFPSTarget;
    _maxSkipFramesPhysics = 10;

    StartBehaviour();
    while (_continueRunning){
        _updateTimer->tick();
        _physicsTimer->tick();
        if(!_isPaused){
            CalculateFrameStatistics();


            DoUpdate(accumulatedTimePhysics, nbLoopsPhysics, *_physicsTimer, _dtPhysics, _maxSkipFramesPhysics, true);
            HandleInput();
            DoUpdate(accumulatedTimeUpdate, nbLoopsUpdate, *_updateTimer, _dtUpdate, _maxSkipFramesUpdate, false);


            Render();

            if(_updateTimer->getTotalTime() > 10.0){
                _continueRunning = false;
            }
        }
    }

    DeInitialize();
    Destroy();
}

void Game::DoUpdate(double& accumulatedTime, int& nbLoops, Timer& timer, double maxDt, int maxLoops, bool isPhysics) {
    accumulatedTime += timer.getDeltaTime();
    nbLoops = 0;
    while(accumulatedTime >= maxDt && nbLoops < maxLoops){
        if(isPhysics){
            PhysicsUpdate(maxDt);
        }
        else {
            Update(maxDt);
        }
        accumulatedTime -= maxDt;
        nbLoops++;
    }
}

void Game::CalculateFrameStatistics() {
    _nFramesForStats ++;
    if ((_updateTimer->getTotalTime() - _elapsedTimeForStats) >= 1.0){
        _fps = _nFramesForStats;
        _milliSecondsPerFrame = 1000.0 / (double ) _fps;

        _nFramesForStats = 0;
        _elapsedTimeForStats += 1.0;
    }
}

void Game::StartBehaviour() {
    //TODO Start
}

void Game::HandleInput() {
    //TODO input
    // Utiliser une lib ?
    // Stocker et dater les inputs
    // ESPACE = Play et PAUSE
}

void Game::Render() {
    // TODO render
}

void Game::Update(double dt) {
    //TODO UPDATE
}

void Game::DeInitialize() {

    //TODO DE init
}

void Game::Destroy() {
    // TODO Destroy
}

void Game::PhysicsUpdate(double dt) {
    // TODO physics update
    DetectCollisions();
}

void Game::DetectCollisions() {

}
