#include <APYI/PyTypes/PyString.h>

ApyiPy_String::ApyiPy_String()
{
    
}

ApyiPy_String::ApyiPy_String(PyObject* other)
{
    selfPy = other;
    m_callData.bHasAttribute = false;
    m_callData.ObjectSize = PyUnicode_GET_LENGTH(selfPy);
    m_callData.TypeName = "String";
}

ApyiPy_String::ApyiPy_String(const ApyiPy_String& rhs)
{
    selfPy = rhs.selfPy;
    m_callData.bHasAttribute = rhs.m_callData.bHasAttribute;
    m_callData.ObjectSize = rhs.m_callData.ObjectSize;
    m_callData.TypeName = rhs.m_callData.TypeName;
}

ApyiPy_String::ApyiPy_String(const std::string& rhs)
{
    selfPy = PyUnicode_FromString(rhs.c_str());
    m_callData.bHasAttribute = false;
    m_callData.ObjectSize = PyUnicode_GET_LENGTH(selfPy);
    m_callData.TypeName = "String";
}

ApyiPy_String& ApyiPy_String::operator=(const std::string& rhs)
{
    Py_CLEAR(selfPy);
    selfPy = PyUnicode_FromString(rhs.c_str());
    m_callData.ObjectSize = PyUnicode_GET_LENGTH(selfPy);
    return *this;
}

char ApyiPy_String::operator[](size_t index)
{
    return (char)(PyUnicode_READ_CHAR(selfPy, index));
}

unsigned int ApyiPy_String::GetLength()
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

bool ApyiPy_String::IsEmpty()
{
    if(PyUnicode_GET_LENGTH(selfPy) == 0)
    {
        return true;
    }
    return false;
}

const char* ApyiPy_String::AsString()
{
    PyObject* temp_bytes = PyUnicode_AsEncodedString(selfPy, "UTF-8", "strict");
    const char* result = PyBytes_AS_STRING(temp_bytes);
    Py_CLEAR(temp_bytes);
    return result;
}

std::ostream& operator<<(std::ostream& os, ApyiPy_String& m_str)
{
    os << m_str.AsString();
    return os;
}

