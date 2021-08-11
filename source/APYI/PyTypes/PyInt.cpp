#include <APYI/PyTypes/PyInt.h>

ApyiPy_Int::ApyiPy_Int()
{
    
}

ApyiPy_Int::ApyiPy_Int(PyObject* val)
{
    selfPy = val;
}

ApyiPy_Int::ApyiPy_Int(const long& other){
    Py_CLEAR(selfPy);
    selfPy = PyLong_FromLong(other);
    
}

ApyiPy_Int::ApyiPy_Int(const ApyiPy_Int& other)
{
    Py_CLEAR(selfPy);
    selfPy = PyLong_FromLong(other.AsCInt());
}

ApyiPy_Int ApyiPy_Int::operator+(const ApyiPyPython& other)
{
    PyObject* result = PyNumber_Add(selfPy, other.GetPySelf());
    return ApyiPy_Int(result);
}

ApyiPy_Int ApyiPy_Int::operator+(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator+=(const ApyiPyPython& other)
{
    PyObject* result = PyNumber_Add(selfPy, other.GetPySelf());
    return ApyiPy_Int(result);
}

ApyiPy_Int ApyiPy_Int::operator+=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator-(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Subtract(selfPy, other.GetPySelf());
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator-(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator-=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Subtract(selfPy, other.GetPySelf());
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator-=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator*(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Multiply(selfPy, other.GetPySelf());
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator*(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator*=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Multiply(selfPy, other.GetPySelf());
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator*=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator/(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_FloorDivide(selfPy, other.GetPySelf());
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator/(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_FloorDivide(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator/=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_FloorDivide(selfPy, other.GetPySelf());
    return ApyiPy_Int(resultant);
}

ApyiPy_Int ApyiPy_Int::operator/=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_FloorDivide(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Int(resultant);
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