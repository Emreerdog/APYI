#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <AdvancedPythonInterface/ObjectUtils/StringUtils.h>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <pathcch.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#elif defined(__unix__) // all unices, not all compilers
#include <unistd.h>
#include <dirent.h>
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

void ApyiPathTraits::EGetCurrentDir(std::wstring& out)
{
    // char buffer[256];
    // GetModuleFileNameA(NULL, buffer, 256);
    // std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    // return std::string(buffer).substr(0, pos);
#ifdef _WIN32

    wchar_t buffer[256];
    GetCurrentDirectoryW(256, buffer);
    out = std::wstring(buffer);
#elif defined(__unix__)
    char cWd[256];
    if(getcwd(cWd, sizeof(cWd)) != NULL)
    {
        //out = sConv.from_bytes(cWd);
        ApyiStringUtils::StringToWide(cWd, out);
    }
    // else
    // Failed somehow
#endif
}

void ApyiPathTraits::EGetExeDir(std::wstring& out)
{

#ifdef _WIN32
    wchar_t buffer[256];
    GetModuleFileNameW(NULL, buffer, 256);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    out = std::wstring(buffer).substr(0, pos).c_str();
#elif defined(__unix__)
    
#endif
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
#elif defined(__unix__)
    DIR* directoryHandle; // Directory descp
    std::string _rootDir = "";
    ApyiStringUtils::WideToString(rootDir, _rootDir);
    directoryHandle = opendir(_rootDir.c_str());
    if(directoryHandle)
    {
        std::vector<std::wstring> workingVector;
        dirent* dirIter;
        while((dirIter = readdir(directoryHandle)) != NULL)
        {
            workingVector.push_back(ApyiStringUtils::StringToWide(dirIter->d_name));
        }
        return workingVector;
    }
    return std::vector<std::wstring>();
#endif
    return std::vector<std::wstring>();
}

std::vector<std::wstring> ApyiPathTraits::GetScriptFiles()
{
    std::wstring tempVal = L"";
    ApyiPathTraits::EGetExeDir(tempVal);
    std::wcout << tempVal + L"\\scripts\\*.py" << std::endl;
    return ApyiPathTraits::GetFilesUnderDirectory(tempVal + L"\\scripts\\*.py");
}