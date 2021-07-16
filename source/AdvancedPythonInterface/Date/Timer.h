#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

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

#endif // TIMER_H_INCLUDED