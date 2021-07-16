#include <AdvancedPythonInterface/Date/Timer.h>

void Er_MiddleFunc(uint32_t milliseconds, const std::function<void()> &target)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    target();
}

void ApyiTimerObject::SetTimer(uint32_t milliseconds, std::function<void()>&& targetFunction)
{
    executeThread = std::thread(Er_MiddleFunc, milliseconds, targetFunction);

}

void ApyiTimerObject::ReleaseTimer()
{
    executeThread.join();
}
