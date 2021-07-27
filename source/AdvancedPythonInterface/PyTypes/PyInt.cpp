#include <AdvancedPythonInterface/PyTypes/PyInt.h>

ApyiPy_Int::ApyiPy_Int()
{
    
}

ApyiPy_Int::ApyiPy_Int(PyObject* val)
{
    selfPy = val;
}

ApyiPy_Int::ApyiPy_Int(long value)
{
    selfPy = PyLong_FromLong(value);

    m_callData.bHasAttribute = false;
    m_callData.TypeName = "long";
    m_callData.ObjectSize = 0;

}

void ApyiPy_Int::operator=(const long& other){
    Py_CLEAR(this->selfPy);
    this->selfPy = PyLong_FromLong(other);

}

ApyiPy_Int ApyiPy_Int::operator+(const ApyiPyPython& other)
{
    PyObject* result = PyNumber_Add(selfPy, other.GetPySelf());
    static ApyiPy_Int tP(result);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator+(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempLong);
    static ApyiPy_Int tP(resultant);

    Py_CLEAR(tempLong);

    return tP;
}

ApyiPy_Int ApyiPy_Int::operator+=(const ApyiPyPython& other)
{
    PyObject* result = PyNumber_Add(selfPy, other.GetPySelf());
    static ApyiPy_Int tP(result);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator+=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempLong);
    static ApyiPy_Int tP(resultant);
    Py_CLEAR(tempLong);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator-(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Subtract(selfPy, other.GetPySelf());
    static ApyiPy_Int tP(resultant);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator-(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempLong);
    static ApyiPy_Int tP(resultant);
    Py_CLEAR(tempLong);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator-=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Subtract(selfPy, other.GetPySelf());
    static ApyiPy_Int tP(resultant);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator-=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempLong);
    static ApyiPy_Int tP(resultant);
    Py_CLEAR(tempLong);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator*(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Multiply(selfPy, other.GetPySelf());
    static ApyiPy_Int tP(resultant);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator*(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempLong);
    static ApyiPy_Int tP(resultant);
    Py_CLEAR(tempLong);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator*=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Multiply(selfPy, other.GetPySelf());
    static ApyiPy_Int tP(resultant);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator*=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempLong);
    static ApyiPy_Int tP(resultant);
    Py_CLEAR(tempLong);
    return tP;
}

ApyiPy_Int ApyiPy_Int::operator/(const ApyiPyPython& other)
{
    return ApyiPy_Int();
}

ApyiPy_Int ApyiPy_Int::operator/(const long& other)
{
    return ApyiPy_Int();
}

ApyiPy_Int ApyiPy_Int::operator/=(const ApyiPyPython& other)
{
    return ApyiPy_Int();
}

ApyiPy_Int ApyiPy_Int::operator/=(const long&)
{
    return ApyiPy_Int();
}

long ApyiPy_Int::AsCInt() const
{
    return PyLong_AsLong(selfPy);
}

ApyiPy_Int::~ApyiPy_Int()
{
    Py_CLEAR(selfPy);
}

std::ostream& operator<<(std::ostream& os, const ApyiPy_Int& other){
    os << other.AsCInt();
    return os;
}