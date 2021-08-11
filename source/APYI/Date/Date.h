#ifndef APYI_DATE_H
#define APYI_DATE_H

#include <iostream>
#include <time.h>

namespace ApyiTime
{
    std::string GetCurrentTime();
    std::string GetFormattedTime(const std::string& format);
    clock_t GetNow();
}

// extern"C" __declspec(dllexport) const char* ErGetCurrentTime();

#endif // APYI_DATE_H