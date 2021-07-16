#include <AdvancedPythonInterface/PyTypes/PyInt.h>

#include <iostream>

ApyiPy_Int::ApyiPy_Int(long value)
{
    selfPy = PyLong_FromLong(value);
    
    Py_ssize_t pSize = PyObject_Size(selfPy);

    PyObject* tempLong = PyLong_FromSsize_t(pSize);
    

    m_callData.bHasAttribute = false;
    m_callData.TypeName = "long";
    m_callData.ObjectSize = PyLong_AsLong(tempLong);

    Py_CLEAR(tempLong);
}

void ApyiPy_Int::operator=(const long& other){
    Py_CLEAR(this->selfPy);
    this->selfPy = PyLong_FromLong(other);

}

void ApyiPy_Int::operator+=(const long& other){
    Py_CLEAR(this->selfPy);
    this->selfPy = PyLong_FromLong(other);

}

ApyiPy_Int::~ApyiPy_Int()
{
    Py_CLEAR(selfPy);
}

void* ApyiPy_Int::Convert_C()
{
    c_val = PyLong_AsLong(selfPy);
    return &c_val;
}