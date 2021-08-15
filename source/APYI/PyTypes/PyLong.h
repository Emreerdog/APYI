#ifndef APYI_PYLONG_H
#define APYI_PYLONG_H

#include <APYI/PyTypes/PyPython.h>
#include <iostream>

class ApyiPy_Float;

class ApyiPy_Long : public ApyiPyPython{
public:
    ApyiPy_Long();
    ApyiPy_Long(const ApyiPy_Long& other);
    ApyiPy_Long(PyObject* val);
    ApyiPy_Long(const int& other);
    ApyiPy_Long(const long& other);
    ApyiPy_Long(const double& other);
    
    /* ADDITION OVERLOADS */
    ApyiPy_Long operator+(const ApyiPyPython& other);
    ApyiPy_Long operator+(const long& other);
    ApyiPy_Long operator+(const int& other);
    ApyiPy_Long operator+(const double& other);
    ApyiPy_Long& operator+=(const ApyiPyPython& other);
    ApyiPy_Long& operator+=(const long& other);
    ApyiPy_Long& operator+=(const int& other);
    ApyiPy_Long& operator+=(const double& other);

    /* SUBTRACTION OVERLOADS */
    ApyiPy_Long operator-(const ApyiPyPython& other);
    ApyiPy_Long operator-(const long& other);
    ApyiPy_Long operator-(const int& other);
    ApyiPy_Long operator-(const double& other);
    ApyiPy_Long& operator-=(const ApyiPyPython& other);
    ApyiPy_Long& operator-=(const long& other);
    ApyiPy_Long& operator-=(const int& other);
    ApyiPy_Long& operator-=(const double& other);
    
    /* MULTIPLICATION OVERLOADS */
    ApyiPy_Long operator*(const ApyiPyPython& other);
    ApyiPy_Long operator*(const long& other);
    ApyiPy_Long operator*(const int& other);
    ApyiPy_Long operator*(const double& other);
    ApyiPy_Long& operator*=(const ApyiPyPython& other);
    ApyiPy_Long& operator*=(const long& other);
    ApyiPy_Long& operator*=(const int& other);
    ApyiPy_Long& operator*=(const double& other);

    /* DIVISION OVERLOADS */
    ApyiPy_Long operator/(const ApyiPyPython& other);
    ApyiPy_Long operator/(const long& other);
    ApyiPy_Long operator/(const int& other);
    ApyiPy_Long operator/(const double& other);
    ApyiPy_Long& operator/=(const ApyiPyPython& other);
    ApyiPy_Long& operator/=(const long& other);
    ApyiPy_Long& operator/=(const int& other);
    ApyiPy_Long& operator/=(const double& other);

    /* TYPE CONVERSIONS */

    long AsCLong() const;

    ~ApyiPy_Long();

    friend std::ostream& operator<<(std::ostream& os, const ApyiPy_Long& other);

private:

    void SelfRestore(PyObject* res);
};

#endif /* APYI_PYLONG_H */