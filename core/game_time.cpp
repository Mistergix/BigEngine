#include "game_time.h"

Time::Time() {
    time = 0.0;
    deltaTime = 1.0 / 60.0;
}

void Time::UpdateTime() {
    // TODO Intervalle fixe
    time += deltaTime;
}

double Time::CurrentTime() const {
    return time;
}
