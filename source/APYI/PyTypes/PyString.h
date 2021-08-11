#include <APYI/PyTypes/PyPython.h>
#include <string>
#include <iostream>

class ApyiPy_String : public ApyiPyPython{
public:
    ApyiPy_String();
    ApyiPy_String(PyObject*);
    ApyiPy_String(const ApyiPy_String&);
    ApyiPy_String(const std::string&);
    ApyiPy_String& operator=(const std::string&);
    char operator[](size_t);
    unsigned int GetLength();
    unsigned int KindValue();
    void* RawData();
    bool IsEmpty();
    const char* AsString();
    friend std::ostream& operator<<(std::ostream& os, ApyiPy_String& m_str);
private:
    
};