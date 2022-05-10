#include "game_time.h"
#include <windows.h>
#include <stdexcept>

Timer::Timer() {
    _startTimeStamp = 0;
    _totalIdleTime = 0;
    _pausedTimeStamp = 0;
    _currentTimeStamp = 0;
    _previousTimeStamp = 0;
    _secondsPerCount = 0.0;
    _deltaTime = 0.0;
    _isStopped = false;

    uint64_t frequency = 0;

    if(QueryPerformanceFrequency((LARGE_INTEGER*)& frequency)){
        _secondsPerCount = 1.0 / (double ) frequency;
    } else{
        throw std::runtime_error("The hardware does not support a high-precision timer!");
    }

}

void Timer::start() {
    if(_isStopped){
        uint64_t now = 0;
        if(QueryPerformanceCounter((LARGE_INTEGER*)& now)){
            _totalIdleTime += (now - _pausedTimeStamp);
            _previousTimeStamp = now;
            _pausedTimeStamp = 0;
            _isStopped = false;
        } else{
            throw std::runtime_error("Unable to query the performance counter!");
        }
    }
}

void Timer::stop() {
    if(!_isStopped){
        uint64_t now = 0;
        if(QueryPerformanceCounter((LARGE_INTEGER*)& now)){
            _pausedTimeStamp = now;
            _isStopped = true;
        } else{
            throw std::runtime_error("Unable to query the performance counter!");
        }
    }
}

void Timer::tick() {
    if (_isStopped){
        _deltaTime = 0.0f;
    } else{
        if(QueryPerformanceCounter((LARGE_INTEGER*)& _currentTimeStamp)){
            _deltaTime = (_currentTimeStamp - _previousTimeStamp) * _secondsPerCount;
            _previousTimeStamp = _currentTimeStamp;
            if(_deltaTime < 0.0){_deltaTime = 0.0;}

        } else{
            throw std::runtime_error("Unable to query the performance counter!");
        }
    }
}

void Timer::reset() {
    uint64_t now = 0;
    if(QueryPerformanceCounter((LARGE_INTEGER*)& now)){
        _startTimeStamp = now;
        _previousTimeStamp = now;
        _pausedTimeStamp = 0;
        _isStopped = false;
    } else{
        throw std::runtime_error("Unable to query the performance counter!");
    }
}

double Timer::getDeltaTime() const {
    return _deltaTime;
}

double Timer::getTotalTime() const {
    if (_isStopped){
        return (_pausedTimeStamp - _startTimeStamp - _totalIdleTime) * _secondsPerCount;
    } else{
        return (_currentTimeStamp - _startTimeStamp - _totalIdleTime) * _secondsPerCount;
    }
}


