#ifndef PYFUNCTIONAL_H
#define PYFUNCTIONAL_H

#include <APYI/PyTypes/PyPython.h>
#include <APYI/PyTypes/PyDict.h>

class ApyiPy_Tuple;

class ApyiPy_Function : public ApyiPyPython{
public:
    ApyiPy_Function();
    ApyiPy_Function(PyObject* other);
    ApyiPy_Function(const ApyiPy_Function& other);
    ~ApyiPy_Function();
    //PyObject* operator()();
    //PyObject* operator()(ApyiPyPython*);

    PyObject* Call();
    PyObject* Call(ApyiPyPython* arg, ApyiDict* kwargs = nullptr);
    void SetFunctionDict(ApyiDict* newDict);
    ApyiDict* GetFunctionDict();
    void AddGlobal(const char* key, ApyiPyPython* targetGlobal);
    // a
private:
    bool closureModified;
    ApyiDict *FunctionGlobals;
    //PyObject* FCELL;
};

#endif /* PYFUNCTIONAL_H */