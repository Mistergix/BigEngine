#ifndef BIG_ENGINE_GAME_TIME_H
#define BIG_ENGINE_GAME_TIME_H

#include <chrono>

struct TimeSource{
    using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
    static TimePoint now() { return std::chrono::high_resolution_clock::now(); }
};

class Timer {
private:
    // measured in counts
    uint64_t _startTimeStamp; // time at application start
    uint64_t _totalIdleTime;
    uint64_t  _pausedTimeStamp;
    uint64_t _currentTimeStamp; // time at the currentFrame;
    uint64_t _previousTimeStamp; // time at the previous frame

    // measured in seconds
    double _secondsPerCount;
    double _deltaTime;

    bool _isStopped;
public:
    Timer();
    double getTotalTime() const; // total time game running (without pause)
    [[nodiscard]] double getDeltaTime() const; // the time between two frames

    void start();
    void reset();
    void tick();
    void stop();

    void SetTimeScale(double d);

    double _timeScale;
};


#endif //BIG_ENGINE_GAME_TIME_H
