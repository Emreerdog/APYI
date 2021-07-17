#ifndef APYI_TIMER_H
#define APYI_TIMER_H

#include <stdint.h>
#include <thread>
#include <functional>

class ApyiTimerObject {
private:
    std::thread executeThread;
public:
    void SetTimer(uint32_t milliseconds, std::function<void()>&& targetFunction);
    void ReleaseTimer();
};

#endif // APYI_TIMER_H