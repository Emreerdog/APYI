#ifndef PYINT_H
#define PYINT_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>
#include <iostream>

class ApyiPy_Int : public ApyiPyPython{
public:
    ApyiPy_Int();
    ApyiPy_Int(PyObject*);
    explicit ApyiPy_Int(long);
    void operator=(const long&);
    
    ApyiPy_Int operator+(const ApyiPyPython&);
    ApyiPy_Int operator+(const long&);
    ApyiPy_Int operator+=(const ApyiPyPython&);
    ApyiPy_Int operator+=(const long&);

    ApyiPy_Int operator-(const ApyiPyPython&);
    ApyiPy_Int operator-(const long&);
    ApyiPy_Int operator-=(const ApyiPyPython&);
    ApyiPy_Int operator-=(const long&);
    
    ApyiPy_Int operator*(const ApyiPyPython&);
    ApyiPy_Int operator*(const long&);
    ApyiPy_Int operator*=(const ApyiPyPython&);
    ApyiPy_Int operator*=(const long&);

    ApyiPy_Int operator/(const ApyiPyPython&);
    ApyiPy_Int operator/(const long&);
    ApyiPy_Int operator/=(const ApyiPyPython&);
    ApyiPy_Int operator/=(const long&);
    long AsCInt() const;

    ~ApyiPy_Int();

    friend std::ostream& operator<<(std::ostream& os, const ApyiPy_Int& other);

private:
    
};

#endif /* PYINT_H */