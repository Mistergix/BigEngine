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
    _timer = new Timer();
    _timer->reset();
    _continueRunning = true;
    double accumulatedTime = 0.0;
    int nbLoops = 0;
    _dt = 1000.0 / 240.0;
    _maxSkipFrames = 10;

    StartBehaviour();
    while (_continueRunning){
        _timer->tick();
        if(!_isPaused){
            CalculateFrameStatistics();
            HandleInput();
            accumulatedTime += _timer->getDeltaTime();
            nbLoops = 0;
            while(accumulatedTime >= _dt && nbLoops < _maxSkipFrames){
                Update(_dt);
                accumulatedTime -= _dt;
                nbLoops++;
            }

            //TODO Physics with different timer
            Render();
        }
    }

    DeInitialize();
    Destroy();
}

void Game::CalculateFrameStatistics() {
    _nFramesForStats ++;
    if ((_timer->getTotalTime() - _elapsedTimeForStats) >= 1.0){
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
