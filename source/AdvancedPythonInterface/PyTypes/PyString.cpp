#include <AdvancedPythonInterface/PyTypes/PyString.h>

ApyiPyString::ApyiPyString()
{
    
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

unsigned int ApyiPyString::GetLength()
{
    return PyUnicode_GET_LENGTH(selfPy);
}

bool ApyiPyString::IsEmpty()
{
    return false;
}

const char* ApyiPyString::AsString()
{
    PyObject* temp_bytes = PyUnicode_AsEncodedString(selfPy, "UTF-8", "strict");
    const char* result = PyBytes_AS_STRING(temp_bytes);
    Py_CLEAR(temp_bytes);
    return result;
}

