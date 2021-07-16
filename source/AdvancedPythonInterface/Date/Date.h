#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <time.h>

namespace ApyiTime
{
    std::string GetCurrentTime();
    std::string GetFormattedTime(const std::string& format);
    clock_t GetNow();
}

// extern"C" __declspec(dllexport) const char* ErGetCurrentTime();

#endif // DATE_H_INCLUDED