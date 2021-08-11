#include <APYI/FileSystem/FileSystem.h>
#include <APYI/Logging/Logger.h>
#include <stdio.h>

#include <iostream>
#include <fstream>

#ifdef _WIN32
    #include <windows.h>
    #include <shlwapi.h>
#elif defined(__unix__) // all unices, not all compilers
    #include <sys/stat.h>
    #include <unistd.h>
#endif

// Standard C style file creation

void ApyiFileSystem::ErCreateFile(const char* fileName)
{
    FILE* fileHandle = fopen(fileName, "w");
    fclose(fileHandle);
}

bool ApyiFileSystem::ErCreateDirectory(const char* directoryName)
{
#ifdef _WIN32
    CreateDirectoryA(directoryName, NULL);
    switch (GetLastError()) {
    case ERROR_ALREADY_EXISTS:
    {
        APYI_LOG(ApyiLogging::APYI_OUT_FILE, ApyiLogging::kError, "Directory couldn't created reason(Already Exists): %s", directoryName);
        return ERROR_ALREADY_EXISTS;
    }
    case ERROR_PATH_NOT_FOUND:
    {
        APYI_LOG(ApyiLogging::APYI_OUT_FILE, ApyiLogging::kError, "Directory couldn't created reason(Path Not Found): %s", directoryName);
        return ERROR_PATH_NOT_FOUND;
    }
    default:
    {
        APYI_LOG(ApyiLogging::APYI_OUT_FILE, ApyiLogging::kError, "Directory created successfully %s", directoryName);
        return 0;
    }
    }
#elif defined(__unix__)
    int resultCheck = mkdir(directoryName, 0777); // Full permission
    if(!resultCheck)
    {
        // Directory created
        APYI_LOG(ApyiLogging::APYI_OUT_FILE, ApyiLogging::kError, "Directory created successfully %s", directoryName);
    }
    else{
        // Failed to create directory
        APYI_LOG(ApyiLogging::APYI_OUT_FILE, ApyiLogging::kError, "Directory couldn't created %s", directoryName);
    }
    return resultCheck;
#endif
}

bool ApyiFileSystem::ErRemoveFile(const char* fileName)
{
#ifdef _WIN32
    DeleteFileA(fileName);
    switch (GetLastError()) {
    case ERROR_FILE_NOT_FOUND:
    {
        APYI_LOG(ApyiLogging::APYI_OUT_FILE, ApyiLogging::kError, "File couldn't removed reason(File not found): %s", fileName);
        return ERROR_FILE_NOT_FOUND;
    }
    case ERROR_ACCESS_DENIED:
    {
        APYI_LOG(ApyiLogging::APYI_OUT_FILE, ApyiLogging::kError, "File couldn't removed reason(File access denied): %s", fileName);
        return ERROR_ACCESS_DENIED;
    }
    default:
    {
        return 0;
    }

    }
#elif defined(__unix__)
    int resultCheck = remove(fileName);
    if(resultCheck == 0)
    {
        // File removed successfully
    }
    else
    {
        APYI_LOG(ApyiLogging::APYI_OUT_FILE, ApyiLogging::kError, "File couldn't removed %s", fileName);
    }
    return resultCheck;
#endif
}

int ApyiFileSystem::ErRemoveDirectory(const char* directoryName)
{
#ifdef _WIN32

    SHFILEOPSTRUCT file_op =
    {
            NULL,
            FO_DELETE,
            directoryName,
            NULL,
            FOF_NOCONFIRMATION |
            FOF_NOERRORUI |
            FOF_SILENT,
            false,
            0,
            NULL
    };
    return SHFileOperation(&file_op);
#elif defined(__unix__)
#endif
}

int ApyiFileSystem::ErRenameFile(const char* fileLocation, const char* newName)
{
#ifdef _WIN32
    SHFILEOPSTRUCT file_op =
    {
            NULL,
            FO_RENAME,
            fileLocation,
            newName,
            FOF_NOCONFIRMATION |
            FOF_NOERRORUI |
            FOF_SILENT,
            false,
            0,
            ""
    };
    return SHFileOperation(&file_op);
#elif defined(__unix__)
#endif
}

void ApyiFileSystem::ErReadFile(const char* fileName, std::string& out)
{
    std::ifstream givenFile(fileName);
    if(givenFile.is_open())
    {
        std::string fileIterator = "";
        std::string fileContent = "";

        while(std::getline(givenFile, fileIterator))
        {
            fileContent += fileIterator;
            fileContent += "\n";
        }
        givenFile.close();
        out = fileContent;
    }
    else{
        APYI_LOG(ApyiLogging::APYI_OUT_FILE, ApyiLogging::kError, "File couldn't found: %s", fileName);
    }
}

const char* ApyiFileSystem::ErDoShit()
{
    std::string* a = new std::string("lolol");
    std::cout << "This shit is called from python but it is C" << std::endl;

    return a->c_str();
}
