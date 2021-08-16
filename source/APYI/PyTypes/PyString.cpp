#include <APYI/PyTypes/PyString.h>

ApyiPy_String::ApyiPy_String()
{
    selfPy = NULL;
}

ApyiPy_String::ApyiPy_String(PyObject* other)
{
    if(selfPy != NULL)
    {
        SelfClean();
    }
    selfPy = other;
    m_callData.bHasAttribute = false;
    m_callData.ObjectSize = PyUnicode_GET_LENGTH(selfPy);
    m_callData.TypeName = "String";
}

ApyiPy_String::ApyiPy_String(const ApyiPy_String& rhs)
{
    if(selfPy != NULL)
    {
        SelfClean();
    }
    PyObject* otherPy = rhs.GetPySelf();
    const char* stringValue = PyUnicode_AS_DATA(otherPy);
    selfPy = PyUnicode_FromString(stringValue);
    m_callData.bHasAttribute = rhs.m_callData.bHasAttribute;
    m_callData.ObjectSize = rhs.m_callData.ObjectSize;
    m_callData.TypeName = rhs.m_callData.TypeName;
}

ApyiPy_String::ApyiPy_String(const std::string& rhs)
{
    if(selfPy != NULL)
    {
        SelfClean();
    }
    selfPy = PyUnicode_FromString(rhs.c_str());
    m_callData.bHasAttribute = false;
    m_callData.ObjectSize = PyUnicode_GET_LENGTH(selfPy);
    m_callData.TypeName = "String";
}

ApyiPy_String ApyiPy_String::operator+(const std::string& rhs)
{
    PyObject* pString = PyUnicode_FromString(rhs.c_str());
    PyObject* result = PyUnicode_Concat(selfPy, pString);
    Py_CLEAR(pString);
    return ApyiPy_String(result);
}

ApyiPy_String ApyiPy_String::operator+(const ApyiPy_String& rhs)
{
    PyObject* result = PyUnicode_Concat(selfPy, rhs.GetPySelf());
    return ApyiPy_String(result);
}

ApyiPy_String& ApyiPy_String::operator+=(const std::string& rhs)
{
    if(selfPy != NULL)
    {
        PyObject* pString = PyUnicode_FromString(rhs.c_str());
        PyObject* result = PyUnicode_Concat(selfPy, pString);
        Py_CLEAR(selfPy);
        Py_CLEAR(pString);
        selfPy = result;
    }
    else
    {
        PyObject* pString = PyUnicode_FromString(rhs.c_str());
        selfPy = pString;
    }
    return *this;
}

ApyiPy_String& ApyiPy_String::operator+=(const ApyiPy_String& rhs)
{
    if(selfPy != NULL)
    {
        PyObject* result = PyUnicode_Concat(selfPy, rhs.GetPySelf());
        Py_CLEAR(selfPy);
        selfPy = result;
    }
    else
    {
        PyObject* pString = PyUnicode_FromObject(rhs.GetPySelf());
        selfPy = pString;
    }
    return *this;
}

uint8_t* ApyiPy_String::operator[](size_t index)
{
    //return (char)(PyUnicode_READ_CHAR(selfPy, index));
    Py_UCS1* result = PyUnicode_1BYTE_DATA(selfPy);
    return result + index;
}

size_t ApyiPy_String::length()
{
    return PyUnicode_GET_LENGTH(selfPy);
}

size_t ApyiPy_String::size()
{
    return PyUnicode_GET_LENGTH(selfPy);
}

unsigned int ApyiPy_String::KindValue()
{
    return PyUnicode_KIND(selfPy);
}

void* ApyiPy_String::RawData()
{
    return PyUnicode_DATA(selfPy);
}

bool ApyiPy_String::empty()
{
    if(PyUnicode_GET_LENGTH(selfPy) == 0)
    {
        return true;
    }
    return false;
}

const char* ApyiPy_String::c_str()
{
    const char* result = PyUnicode_AsUTF8(selfPy);
    return result;
}

ApyiPy_String ApyiPy_String::substr(ApyiPy_String* str, size_t start, size_t end)
{
    return ApyiPy_String();
}

std::ostream& operator<<(std::ostream& os, ApyiPy_String& m_str)
{
    os << m_str.c_str();
    return os;
}

