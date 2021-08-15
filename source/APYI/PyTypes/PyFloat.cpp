#include <APYI/PyTypes/PyFloat.h>
#include <APYI/PyTypes/PyString.h>
#include <APYI/ObjectUtils/Numbers.h>

ApyiPy_Float::ApyiPy_Float()
{
    
}

ApyiPy_Float::ApyiPy_Float(PyObject* val)
{
    
    SelfClean();
    selfPy = val;
}

ApyiPy_Float::ApyiPy_Float(const char* other){
    SelfClean();
    ApyiPy_String tempString = other;
    selfPy = PyFloat_FromString(tempString.GetPySelf());
}

ApyiPy_Float::ApyiPy_Float(const double& other)
{
    SelfClean();
    selfPy = PyFloat_FromDouble(other);
}

ApyiPy_Float::ApyiPy_Float(const long& other)
{
    SelfClean();
    selfPy = ApyiNumberUtils::FloatFromDecimal(other);
}

ApyiPy_Float::ApyiPy_Float(const int& other)
{
    SelfClean();
    selfPy = ApyiNumberUtils::FloatFromDecimal(other);
}


ApyiPy_Float::ApyiPy_Float(const ApyiPy_Float& other)
{
    SelfClean();
    selfPy = PyFloat_FromDouble(other.AsCDouble());
}

ApyiPy_Float ApyiPy_Float::operator+(const ApyiPyPython& other)
{
    PyObject* result = PyNumber_Add(selfPy, other.GetPySelf());
    return ApyiPy_Float(result);
}

ApyiPy_Float ApyiPy_Float::operator+(const double& other)
{
    PyObject* tempFloat = PyFloat_FromDouble(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator+(const int& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator+(const long& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}


ApyiPy_Float& ApyiPy_Float::operator+=(const ApyiPyPython& other)
{
    PyObject* result = PyNumber_Add(selfPy, other.GetPySelf());
    SelfRestore(result);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator+=(const double& other)
{
    PyObject* tempFloat = PyFloat_FromDouble(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator+=(const int& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator+=(const long& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Add(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}


ApyiPy_Float ApyiPy_Float::operator-(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Subtract(selfPy, other.GetPySelf());
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator-(const double& other)
{
    PyObject* tempFloat = PyFloat_FromDouble(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator-(const int& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator-(const long& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}


ApyiPy_Float& ApyiPy_Float::operator-=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Subtract(selfPy, other.GetPySelf());
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator-=(const double& other)
{
    PyObject* tempFloat = PyFloat_FromDouble(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator-=(const int& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator-=(const long& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Subtract(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float ApyiPy_Float::operator*(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Multiply(selfPy, other.GetPySelf());
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator*(const double& other)
{
    PyObject* tempFloat = PyFloat_FromDouble(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator*(const int& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator*(const long& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float& ApyiPy_Float::operator*=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_Multiply(selfPy, other.GetPySelf());
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator*=(const double& other)
{
    PyObject* tempFloat = PyFloat_FromDouble(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator*=(const int& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator*=(const long& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_Multiply(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float ApyiPy_Float::operator/(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_TrueDivide(selfPy, other.GetPySelf());
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator/(const double& other)
{
    PyObject* tempFloat = PyFloat_FromDouble(other);
    PyObject* resultant = PyNumber_TrueDivide(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator/(const int& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_TrueDivide(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float ApyiPy_Float::operator/(const long& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_TrueDivide(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    return ApyiPy_Float(resultant);
}

ApyiPy_Float& ApyiPy_Float::operator/=(const ApyiPyPython& other)
{
    PyObject* resultant = PyNumber_TrueDivide(selfPy, other.GetPySelf());
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator/=(const double& other)
{
    PyObject* tempFloat = PyFloat_FromDouble(other);
    PyObject* resultant = PyNumber_TrueDivide(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator/=(const int& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_TrueDivide(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

ApyiPy_Float& ApyiPy_Float::operator/=(const long& other)
{
    PyObject* tempFloat = PyLong_FromLong(other);
    PyObject* resultant = PyNumber_TrueDivide(selfPy, tempFloat);
    Py_CLEAR(tempFloat);
    SelfRestore(resultant);
    return *this;
}

double ApyiPy_Float::AsCDouble() const
{
    return PyFloat_AsDouble(selfPy);
}

ApyiPy_Float::~ApyiPy_Float()
{
    SelfClean();
}

void ApyiPy_Float::SelfRestore(PyObject* res)
{
    SelfClean();
    selfPy = res;
}

std::ostream& operator<<(std::ostream& os, const ApyiPy_Float& other){
    os << other.AsCDouble();
    return os;
}