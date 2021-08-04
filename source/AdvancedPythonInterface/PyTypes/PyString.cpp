#include <AdvancedPythonInterface/PyTypes/PyString.h>

ApyiPyString::ApyiPyString()
{
    
}

ApyiPyString::ApyiPyString(PyObject* other)
{
    selfPy = other;
    m_callData.bHasAttribute = false;
    m_callData.ObjectSize = PyUnicode_GET_LENGTH(selfPy);
    m_callData.TypeName = "String";
}

ApyiPyString::ApyiPyString(const ApyiPyString& rhs)
{
    selfPy = rhs.selfPy;
    m_callData.bHasAttribute = rhs.m_callData.bHasAttribute;
    m_callData.ObjectSize = rhs.m_callData.ObjectSize;
    m_callData.TypeName = rhs.m_callData.TypeName;
}

ApyiPyString::ApyiPyString(const std::string& rhs)
{
    selfPy = PyUnicode_FromString(rhs.c_str());
    m_callData.bHasAttribute = false;
    m_callData.ObjectSize = PyUnicode_GET_LENGTH(selfPy);
    m_callData.TypeName = "String";
}

ApyiPyString& ApyiPyString::operator=(const std::string& rhs)
{
    Py_CLEAR(selfPy);
    selfPy = PyUnicode_FromString(rhs.c_str());
    m_callData.ObjectSize = PyUnicode_GET_LENGTH(selfPy);
    return *this;
}

char ApyiPyString::operator[](size_t index)
{
    return (char)(PyUnicode_READ_CHAR(selfPy, index));
}

unsigned int ApyiPyString::GetLength()
{
    return PyUnicode_GET_LENGTH(selfPy);
}

unsigned int ApyiPyString::KindValue()
{
    return PyUnicode_KIND(selfPy);
}

void* ApyiPyString::RawData()
{
    return PyUnicode_DATA(selfPy);
}

bool ApyiPyString::IsEmpty()
{
    if(PyUnicode_GET_LENGTH(selfPy) == 0)
    {
        return true;
    }
    return false;
}

const char* ApyiPyString::AsString()
{
    PyObject* temp_bytes = PyUnicode_AsEncodedString(selfPy, "UTF-8", "strict");
    const char* result = PyBytes_AS_STRING(temp_bytes);
    Py_CLEAR(temp_bytes);
    return result;
}

std::ostream& operator<<(std::ostream& os, ApyiPyString& m_str)
{
    os << m_str.AsString();
    return os;
}

