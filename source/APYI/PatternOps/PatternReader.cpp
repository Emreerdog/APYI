#include <APYI/PatternOps/PatternReader.h>
#include <APYI/FileSystem/FileSystem.h>
#include <sstream>

#include <iostream>

ApyiPatternReader::ApyiPatternReader(bool bReadSymbols)
{
    symbols.reserve(4);
    bIsReadSym = bReadSymbols;
}

unsigned int ApyiPatternReader::ReadPatterned(const std::string& givenFile, std::string& out)
{
    std::string FileContent = "";
    ApyiFileSystem::ErReadFile(givenFile.c_str(), FileContent);
    

    std::istringstream linedString(FileContent);
    std::string eachLine;

    bool firstSymbolFound = false;

    while(std::getline(linedString, eachLine))
    {
        if(firstSymbolFound)
        {
            if(eachLine == "EP!}")
            {
                firstSymbolFound = false;
            }
            else{
                out += eachLine + "\n";
            }
        }

        if(eachLine == "{!EP" && !firstSymbolFound)
        {
            firstSymbolFound = true;
        }
    }

    return 1;
}

std::vector<SSymbolData> ApyiPatternReader::GetSymbols()
{
    return symbols;
}