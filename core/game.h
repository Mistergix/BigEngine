//
// Created by nicol on 10/05/2022.
//

#ifndef BIG_ENGINE_GAME_H
#define BIG_ENGINE_GAME_H


#include "game_time.h"

class Game {
public:
    void Run();

protected:
    Timer* _timer;
    int _fps;
    double _milliSecondsPerFrame;
    int _nFramesForStats = 0;
    double _elapsedTimeForStats = 0.0;
    double _dt;
    double _maxSkipFrames;

    void CalculateFrameStatistics();
    void Update(double dt);

    void StartBehaviour();

    bool _continueRunning;
    bool _isPaused;

    void HandleInput();

    void Render();

    void DeInitialize();

    void Destroy();
};


#endif //BIG_ENGINE_GAME_H
