#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <stdarg.h>
#include <stdio.h>
#include <string>

#include <AdvancedPythonInterface/Date/Date.h>

namespace ApyiLogging
{
    enum LogLevel {
        kError,
        kWarning,
        kSuccess,
        kDefault
    };

    enum LogTarget{
        APYI_OUT_FILE,
        APYI_OUT_CONSOLE
    };

    static FILE* LogFile = fopen("apyi_logs.txt", "a");
    /*
    * C printf(format) like logging function
    * It prints the output to specified log file
    */
    inline void LOG(LogTarget LT, LogLevel LL, std::string&& functionName, int lineNumber, const char* format, ...)
    {
        const std::string logOutput = ApyiTime::GetFormattedTime("Day(%m/%d/%y) Clock(%H:%M:%S)") + " on Function(" + functionName + ") at line(" + std::to_string(lineNumber) + ") == " + format + "\n";
        va_list args;
        va_start(args, format);
        if(LT == LogTarget::APYI_OUT_CONSOLE)
        {
            vfprintf(stdout, logOutput.c_str(), args);
        }
        else
        {
            std::cout << "File logged" << std::endl;
            vfprintf(LogFile, logOutput.c_str(), args);
        }
        va_end(args);
    }
}

#define APYI_LOG(LT, LL, format, ...) ApyiLogging::LOG(LT, LL, __func__, __LINE__, format, __VA_ARGS__)

#endif // LOGGER_H_INCLUDED
