#ifndef BIG_ENGINE_GAME_TIME_H
#define BIG_ENGINE_GAME_TIME_H

class Time {
    double time;
    double deltaTime;
public:
    Time();
    void UpdateTime();

    [[nodiscard]] double CurrentTime() const;
};


#endif //BIG_ENGINE_GAME_TIME_H
