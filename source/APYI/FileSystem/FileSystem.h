#ifndef APYI_FILESYSTEM_H
#define APYI_FILESYSTEM_H

#include <stdint.h>
#include <string>

#ifdef _WIN32
    #define WIN_EXPORTS __declspec(dllexport)
#elif defined(__linux__)
    #undef WIN_EXPORTS
#endif

namespace ApyiFileSystem
{
    
    void ErCreateFile(const char* fileName);
    bool ErCreateDirectory(const char* directoryName);
    bool ErRemoveFile(const char* fileName);
    const char* ErDoShit();
    int ErRemoveDirectory(const char* directoryName);
    int ErRenameFile(const char* fileLocation, const char* newName);
    void ErReadFile(const char* fileName, std::string& out);
    
}

#endif //APYI_FILESYSTEM_H