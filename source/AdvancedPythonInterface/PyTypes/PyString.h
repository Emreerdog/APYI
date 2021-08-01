#include <AdvancedPythonInterface/PyTypes/PyPython.h>
#include <string>

class ApyiPyString : public ApyiPyPython{
public:
    ApyiPyString();
    ApyiPyString(const std::string&);
    ApyiPyString& operator=(const std::string&);
    unsigned int GetLength();
    bool IsEmpty();
    const char* AsString();
private:
    
};