#include <AdvancedPythonInterface/PyTypes/PyPython.h>
#include <string>
#include <iostream>

class ApyiPyString : public ApyiPyPython{
public:
    ApyiPyString();
    ApyiPyString(PyObject*);
    ApyiPyString(const ApyiPyString&);
    ApyiPyString(const std::string&);
    ApyiPyString& operator=(const std::string&);
    char operator[](size_t);
    unsigned int GetLength();
    unsigned int KindValue();
    void* RawData();
    bool IsEmpty();
    const char* AsString();
    friend std::ostream& operator<<(std::ostream& os, ApyiPyString& m_str);
private:
    
};