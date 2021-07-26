#include <AdvancedPythonInterface/PyTypes/PyPython.h>


class ApyiPyString : public ApyiPyPython{
public:
    ApyiPyString();
    ApyiPyString(const std::string&);
    unsigned int GetLength();
    bool IsEmpty();
private:
    std::string mString;
};