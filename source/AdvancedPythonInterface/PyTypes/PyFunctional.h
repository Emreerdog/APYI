#ifndef PYFUNCTIONAL_H
#define PYFUNCTIONAL_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>

class ApyiDict;

class ApyiPy_Function : public ApyiPyPython{
public:
    ApyiPy_Function();
    PyObject* CallFunc();
    ApyiDict* GetFunctionDict();
    void SetFunctionDict(ApyiDict*);
    void AddGlobal(const std::string& , ApyiPyPython*);
    // a
private:
    ApyiDict* FunctionGlobals;
};

#endif /* PYFUNCTIONAL_H */