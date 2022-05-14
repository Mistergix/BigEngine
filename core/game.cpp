//
// Created by nicol on 10/05/2022.
//

#include "game.h"

void Game::Run() {
    std::string scenePath = "Assets/Scenes/SceneTest.scene";
    _scene = new Scene(scenePath);
    std::cout << _scene->name() << std::endl;
    auto gos = FIND_OBJECTS_OF_TYPE(RigidBody);
    auto gosWithTag = GameObject::FindObjectsWithTag("bibi");
    std::cout << gos->size() << " of type RigidBody" <<  std::endl;
    std::cout << gosWithTag->size() << " with tag bibi" <<  std::endl;
    //TODO refactor the timers in separate modules
    _updateTimer = new Timer();
    _updateTimer->reset();
    _physicsTimer = new Timer();
    _physicsTimer->reset();

    _continueRunning = true;
    _isPaused = false;

    double accumulatedTimeUpdate = 0.0;
    int nbLoopsUpdate = 0;
    double accumulatedTimePhysics = 0.0;
    int nbLoopsPhysics = 0;

    const int updateFPSTarget = 60;
    const int physicsFPSTarget = 100;

    _dtUpdate = 1.0 / updateFPSTarget;
    _maxSkipFramesUpdate = 10;
    _dtPhysics = 1.0 / physicsFPSTarget;
    _maxSkipFramesPhysics = 10;

    _timeScale = 1.0;

    StartBehaviour();
    while (_continueRunning){
        _updateTimer->SetTimeScale(_timeScale);
        _physicsTimer->SetTimeScale(_timeScale);
        _updateTimer->tick();
        _physicsTimer->tick();

        //std::cout << "UPDATE Total Time " << _updateTimer->getTotalTime() << std::endl;
        if(!_isPaused){
            CalculateFrameStatistics();
            //std::cout << "FPS = " << _fps << ", MS = " << _milliSecondsPerFrame << std::endl;
            DoUpdate(accumulatedTimePhysics, nbLoopsPhysics, *_physicsTimer, _dtPhysics, _maxSkipFramesPhysics, true);
            HandleInput();
            DoUpdate(accumulatedTimeUpdate, nbLoopsUpdate, *_updateTimer, _dtUpdate, _maxSkipFramesUpdate, false);


            Render();
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
            std::cout << "DO PHYSICS UPDATE" << std::endl;
            PhysicsUpdate(maxDt);
        }
        else {
            std::cout << "DO UPDATE" << std::endl;
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
    for (auto obj  : _scene->GetObjects()) {
        obj->OnStart();
    }
}

void Game::HandleInput() {
    //TODO input
    // Utiliser une lib ?
    // Stocker et dater les inputs
    // ESPACE = Play et PAUSE
    // + : create a prefab
    // - : destroy a random go
    // up and down arrows = time scale
    // escape = quitter
/*
    if (IsKeyDown(VK_ESCAPE)){
        _continueRunning = false;
    }

    if (IsKeyDown(VK_UP)){
        _timeScale += 0.1;
        std::cout << " TIme scale is " << _timeScale << std::endl;
    }

    if (IsKeyDown(VK_DOWN)){
        _timeScale -= 0.1;
        if(_timeScale < 0.0) {_timeScale = 0.0;}
        std::cout << " TIme scale is " << _timeScale << std::endl;
    }

    if(IsKeyDown(VK_SPACE)){
        TogglePause();
    }

    // +
    if(IsKeyDown(VK_ADD)){
        InstantiatePrefab("987654321");
    }

    if(IsKeyDown(VK_SUBTRACT)){
        DeleteRandomObject();
    }*/


}

void Game::Render() {
    // TODO render
}

void Game::Update(double dt) {
    for (auto obj  : _scene->GetObjects()) {
        obj->Update(dt);
    }
}

void Game::DeInitialize() {

    //TODO DE init
}

void Game::Destroy() {
    _scene->Destroy();
    delete _updateTimer;
    delete _physicsTimer;
    delete _scene;
}

void Game::PhysicsUpdate(double dt) {
    for (auto obj  : _scene->GetObjects()) {
        obj->PhysicsUpdate(dt);
    }
    DetectCollisions();
}

void Game::DetectCollisions() {

}

void Game::InstantiatePrefab(const std::string& guid) {
    _scene->CreateObject(guid);
}

void Game::DeleteRandomObject() {
    _scene->TryDeleteFirstObject();
}

void Game::TogglePause() {
    _isPaused = !_isPaused;
    if(_isPaused){
        _updateTimer->stop();
        _physicsTimer->stop();
    }
    else{
        _updateTimer->start();
        _physicsTimer->start();
    }
}
