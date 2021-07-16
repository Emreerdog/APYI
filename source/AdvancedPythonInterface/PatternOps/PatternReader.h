#include <string>
#include <vector>

struct SSymbolData {
    const char* symbol_name;
    const char* symbol_type;
    unsigned int symbol_size;
};

class ApyiPatternReader {
public:
    ApyiPatternReader(bool bReadSymbols = false);
    unsigned int ReadPatterned(const std::string& givenFile, std::string& out);
    std::vector<SSymbolData> GetSymbols();

private:
    std::vector<SSymbolData> symbols;
    bool bIsReadSym;
};
