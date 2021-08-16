#include <APYI/PyTypes/PyPython.h>
#include <string>
#include <iostream>

class ApyiPy_String : public ApyiPyPython{
public:
    ApyiPy_String();
    ApyiPy_String(PyObject* other);
    ApyiPy_String(const ApyiPy_String& rhs);
    ApyiPy_String(const std::string& rhs);

    ApyiPy_String operator+(const std::string& rhs);
    ApyiPy_String operator+(const ApyiPy_String& rhs);
    ApyiPy_String& operator+=(const std::string& rhs);
    ApyiPy_String& operator+=(const ApyiPy_String& rhs);

    uint8_t* operator[](size_t index);
    char begin();
    char end();
    size_t length();
    size_t size();
    void* RawData();
    bool empty();
    const char* c_str();
    ApyiPy_String substr(ApyiPy_String* str, size_t start, size_t end);
    friend std::ostream& operator<<(std::ostream& os, ApyiPy_String& m_str);
private:
    unsigned int KindValue();
};