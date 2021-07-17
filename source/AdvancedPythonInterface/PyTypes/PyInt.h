#ifndef PYINT_H
#define PYINT_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>

class ApyiPy_Int : public ApyiPyPython{
public:
    explicit ApyiPy_Int(long value);
    void operator=(const long& other);
    void operator+=(const long& other);
    ~ApyiPy_Int();
    void* Convert_C();
private:
    long c_val;
};

#endif /* PYINT_H */