#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#elif defined(__unix__) // all unices, not all compilers
#elif defined(__linux__)
#elif defined(__APPLE__)
#endif

bool ApyiPathTraits::SetRoot(const std::string& rootDir)
{

    // Converting to LPCWSTR
    /*
    int len = 0;
    int stringLength = (int)rootDir.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, rootDir.c_str(), stringLength, 0, 0);
    wchar_t* buffer = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, rootDir.c_str(), stringLength, buffer, len);
    std::wstring wwstr(buffer);
    delete [] buffer;*/

#ifdef _WIN32
    SetCurrentDirectoryA(rootDir.c_str());
    return true;
#endif
    return true;
}

const wchar_t* ApyiPathTraits::EGetCurrentDir()
{
    // char buffer[256];
    // GetModuleFileNameA(NULL, buffer, 256);
    // std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    // return std::string(buffer).substr(0, pos);
#ifdef _WIN32

    wchar_t buffer[256];
    GetCurrentDirectoryW(256, buffer);
    return std::wstring(buffer).c_str();
#endif
    return std::wstring(L"").c_str();
}

const wchar_t* ApyiPathTraits::EGetExeDir()
{

#ifdef _WIN32
    wchar_t buffer[256];
    GetModuleFileNameW(NULL, buffer, 256);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return std::wstring(buffer).substr(0, pos).c_str();
#endif
    return std::wstring(L"").c_str();
}

void ApyiPathTraits::UnlLoop()
{
    while(1)
    {
        std::cout << "Fuck this" << std::endl;
    }
}

std::vector<std::wstring> ApyiPathTraits::GetFilesUnderDirectory(const std::wstring& rootDir)
{

#ifdef _WIN32
    WIN32_FIND_DATAW ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    std::vector<std::wstring> workingVector;

    hFind = FindFirstFileW(rootDir.c_str(), &ffd);
    do{
        workingVector.push_back(ffd.cFileName);
    }while(FindNextFileW(hFind, &ffd) != 0);

    FindClose(hFind);
    return workingVector;

#endif
    return std::vector<std::wstring>();
}