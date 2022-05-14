//
// Created by nicol on 10/05/2022.
//

#ifndef BIG_ENGINE_GAME_H
#define BIG_ENGINE_GAME_H


#include "game_time.h"
#include "../scenes/scene.h"

class Game {
public:
    void Run();

protected:
    Scene* _scene;
    Timer* _updateTimer;
    Timer* _physicsTimer;
    int _fps;
    double _milliSecondsPerFrame;
    int _nFramesForStats = 0;
    double _elapsedTimeForStats = 0.0;
    double _dtUpdate;
    int _maxSkipFramesUpdate;
    double _dtPhysics;
    int _maxSkipFramesPhysics;

    void CalculateFrameStatistics();
    void Update(double dt);

    void StartBehaviour();

    bool _continueRunning;
    bool _isPaused;

    void HandleInput();

    void Render();

    void DeInitialize();

    void Destroy();

    void DoUpdate(double& accumulatedTimeUpdate, int& nbLoopsUpdate, Timer& timer, double maxDt, int maxLoops, bool isPhysics);

    void PhysicsUpdate(double dt);

    void DetectCollisions();

    inline bool IsKeyDown(int keyCode)
    {
       // return ((GetAsyncKeyState(keyCode) & 0x8000) ? 1 : 0);
       return false;
    };

    inline bool IsKeyUp(int keyCode)
    {
        //return ((GetAsyncKeyState(keyCode) & 0x8000) ? 0 : 1);
        return false;
    };
    double _timeScale;

    void InstantiatePrefab(const std::string& guid);

    void DeleteRandomObject();

    void TogglePause();
};


#endif //BIG_ENGINE_GAME_H
