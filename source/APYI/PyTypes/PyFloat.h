#ifndef APYI_PYFLOAT_H
#define APYI_PYFLOAT_H

#include <APYI/PyTypes/PyPython.h>

class ApyiPy_Float : public ApyiPyPython{
public:
    ApyiPy_Float();
    ApyiPy_Float(const ApyiPy_Float& other);
    ApyiPy_Float(PyObject* val);
    ApyiPy_Float(const char* other);
    ApyiPy_Float(const double& other);
    ApyiPy_Float(const int& other);
    ApyiPy_Float(const long& other);

    /* ADDITION OVERLOADS */
    ApyiPy_Float operator+(const ApyiPyPython& other);
    ApyiPy_Float operator+(const double& other);
    ApyiPy_Float operator+(const int& other);
    ApyiPy_Float operator+(const long& other);
    ApyiPy_Float& operator+=(const ApyiPyPython& other);
    ApyiPy_Float& operator+=(const double& other);
    ApyiPy_Float& operator+=(const int& other);
    ApyiPy_Float& operator+=(const long& other);

    /* SUBTRACTION OVERLOADS */
    ApyiPy_Float operator-(const ApyiPyPython& other);
    ApyiPy_Float operator-(const double& other);
    ApyiPy_Float operator-(const int& other);
    ApyiPy_Float operator-(const long& other);
    ApyiPy_Float& operator-=(const ApyiPyPython& other);
    ApyiPy_Float& operator-=(const double& other);
    ApyiPy_Float& operator-=(const int& other);
    ApyiPy_Float& operator-=(const long& other);
    
    /* MULTIPLICATION OVERLOADS */
    ApyiPy_Float operator*(const ApyiPyPython& other);
    ApyiPy_Float operator*(const double& other);
    ApyiPy_Float operator*(const int& other);
    ApyiPy_Float operator*(const long& other);
    ApyiPy_Float& operator*=(const ApyiPyPython& other);
    ApyiPy_Float& operator*=(const double& other);
    ApyiPy_Float& operator*=(const int& other);
    ApyiPy_Float& operator*=(const long& other);

    /* DIVISION OVERLOADS */
    ApyiPy_Float operator/(const ApyiPyPython& other);
    ApyiPy_Float operator/(const double& other);
    ApyiPy_Float operator/(const int& other);
    ApyiPy_Float operator/(const long& other);
    ApyiPy_Float& operator/=(const ApyiPyPython& other);
    ApyiPy_Float& operator/=(const double& other);
    ApyiPy_Float& operator/=(const int& other);
    ApyiPy_Float& operator/=(const long& other);
    
    double AsCDouble() const;

    ~ApyiPy_Float();

    friend std::ostream& operator<<(std::ostream& os, const ApyiPy_Float& other);

private:
    void SelfRestore(PyObject* res);
};

#endif /* APYI_PYFLOAT_H */