#ifndef APYI_PATHTRAITS_H
#define APYI_PATHTRAITS_H

#include <string>
#include <vector>

namespace ApyiPathTraits{
    bool SetRoot(const std::string& rootDir);
    void EGetCurrentDir(std::wstring&);
    void EGetExeDir(std::wstring&);
    void UnlLoop();
    std::vector<std::wstring> GetFilesUnderDirectory(const std::wstring& rootDir);
    std::vector<std::wstring> GetScriptFiles();
}

#endif /* APYI_PATHTRAITS_H */