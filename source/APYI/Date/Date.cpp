#include <APYI/Date/Date.h>

std::string ApyiTime::GetCurrentTime()
{
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return asctime(timeinfo);
}

std::string ApyiTime::GetFormattedTime(const std::string& format)
{
    time_t timer = time(NULL);
    tm* tm_info = localtime(&timer);

    char buffer[128];
    strftime(buffer, sizeof(buffer), format.c_str(), tm_info);

    return std::string(buffer);
}

clock_t ApyiTime::GetNow()
{
    return clock();
}

//extern"C" __declspec(dllexport) const char* ErGetCurrentTime()
//{
//    return ErTime::GetCurrentTime().c_str();
//}
