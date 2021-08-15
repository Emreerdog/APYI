#ifndef PYLONG_H
#define PYLONG_H

#include <APYI/PyTypes/PyPython.h>
#include <iostream>

class ApyiPy_Long : public ApyiPyPython{
public:
    ApyiPy_Long();
    ApyiPy_Long(const ApyiPy_Long&);
    ApyiPy_Long(PyObject*);
    ApyiPy_Long(const int&);
    ApyiPy_Long(const long&);
    ApyiPy_Long(const double&);

    ApyiPy_Long operator+(const ApyiPyPython&);
    ApyiPy_Long operator+(const long&);
    ApyiPy_Long& operator+=(const ApyiPyPython&);
    ApyiPy_Long& operator+=(const long&);

    ApyiPy_Long operator-(const ApyiPyPython&);
    ApyiPy_Long operator-(const long&);
    ApyiPy_Long& operator-=(const ApyiPyPython&);
    ApyiPy_Long& operator-=(const long&);
    
    ApyiPy_Long operator*(const ApyiPyPython&);
    ApyiPy_Long operator*(const long&);
    ApyiPy_Long& operator*=(const ApyiPyPython&);
    ApyiPy_Long& operator*=(const long&);

    ApyiPy_Long operator/(const ApyiPyPython&);
    ApyiPy_Long operator/(const long&);
    ApyiPy_Long& operator/=(const ApyiPyPython&);
    ApyiPy_Long& operator/=(const long&);
    long AsCLong() const;

    ~ApyiPy_Long();

    friend std::ostream& operator<<(std::ostream& os, const ApyiPy_Long& other);

private:
    void SelfRestore(PyObject*);
};

#endif /* PYINT_H */