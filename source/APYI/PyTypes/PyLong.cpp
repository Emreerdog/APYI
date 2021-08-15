#include <APYI/PyTypes/PyLong.h>

ApyiPy_Long::ApyiPy_Long()
{
    
}

ApyiPy_Long::ApyiPy_Long(PyObject* val)
{
    
    SelfClean();
    selfPy = val;
}

ApyiPy_Long::ApyiPy_Long(const int& other)
{
    SelfClean();
    selfPy = PyLong_FromLong(other);
}

ApyiPy_Long::ApyiPy_Long(const long& other){
    SelfClean();
    selfPy = PyLong_FromLong(other);
}

ApyiPy_Long::ApyiPy_Long(const double& other)
{
    SelfClean();
    selfPy = PyLong_FromDouble(other);
}

ApyiPy_Long::ApyiPy_Long(const ApyiPy_Long& other)
{
    SelfClean();
    selfPy = PyLong_FromLong(other.AsCLong());
}

ApyiPy_Long ApyiPy_Long::operator+(const ApyiPyPython& other)
{
    PyObject* result = PyNumber_Add(selfPy, other.GetPySelf());
    return ApyiPy_Long(result);
}

ApyiPy_Long ApyiPy_Long::operator+(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Long(resultant);
}

ApyiPy_Long& ApyiPy_Long::operator+=(const ApyiPyPython& other)
{
    PyObject* result = PyNumber_Add(selfPy, other.GetPySelf());
    SelfRestore(result);
    return *this;
}

ApyiPy_Long& ApyiPy_Long::operator+=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempLong);
    Py_CLEAR(tempLong);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Long ApyiPy_Long::operator-(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Subtract(selfPy, other.GetPySelf());
    return ApyiPy_Long(resultant);
}

ApyiPy_Long ApyiPy_Long::operator-(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Long(resultant);
}

ApyiPy_Long& ApyiPy_Long::operator-=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Subtract(selfPy, other.GetPySelf());
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Long& ApyiPy_Long::operator-=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempLong);
    Py_CLEAR(tempLong);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Long ApyiPy_Long::operator*(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Multiply(selfPy, other.GetPySelf());
    return ApyiPy_Long(resultant);
}

ApyiPy_Long ApyiPy_Long::operator*(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Long(resultant);
}

ApyiPy_Long& ApyiPy_Long::operator*=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Multiply(selfPy, other.GetPySelf());
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Long& ApyiPy_Long::operator*=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempLong);
    Py_CLEAR(tempLong);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Long ApyiPy_Long::operator/(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_FloorDivide(selfPy, other.GetPySelf());
    return ApyiPy_Long(resultant);
}

ApyiPy_Long ApyiPy_Long::operator/(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_FloorDivide(selfPy, tempLong);
    Py_CLEAR(tempLong);
    return ApyiPy_Long(resultant);
}

ApyiPy_Long& ApyiPy_Long::operator/=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_FloorDivide(selfPy, other.GetPySelf());
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Long& ApyiPy_Long::operator/=(const long& other)
{
    PyObject* tempLong = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_FloorDivide(selfPy, tempLong);
    Py_CLEAR(tempLong);
    SelfRestore(resultant);
    return *this;
}

long ApyiPy_Long::AsCLong() const
{
    return PyLong_AsLong(selfPy);
}

ApyiPy_Long::~ApyiPy_Long()
{
    SelfClean();
}

void ApyiPy_Long::SelfRestore(PyObject* res)
{
    SelfClean();
    selfPy = res;
}

std::ostream& operator<<(std::ostream& os, const ApyiPy_Long& other){
    os << other.AsCLong();
    return os;
}