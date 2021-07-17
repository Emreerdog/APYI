#ifndef APYI_PATHTRAITS_H
#define APYI_PATHTRAITS_H

#include <string>
#include <vector>

namespace ApyiPathTraits{
    bool SetRoot(const std::string& rootDir);
    const wchar_t* EGetCurrentDir();
    const wchar_t* EGetExeDir();
    void UnlLoop();
    std::vector<std::wstring> GetFilesUnderDirectory(const std::wstring& rootDir);
}

#endif /* APYI_PATHTRAITS_H */