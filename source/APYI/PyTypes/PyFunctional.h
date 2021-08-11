#ifndef PYFUNCTIONAL_H
#define PYFUNCTIONAL_H

#include <APYI/PyTypes/PyPython.h>
#include <APYI/PyTypes/PyDict.h>

class ApyiPy_Tuple;

class ApyiPy_Function : public ApyiPyPython{
public:
    ApyiPy_Function();
    ApyiPy_Function(PyObject*);
    ApyiPy_Function(const ApyiPy_Function&);
    ~ApyiPy_Function();
    //PyObject* operator()();
    //PyObject* operator()(ApyiPyPython*);

    PyObject* Call();
    PyObject* Call(ApyiPyPython*);
    ApyiDict* GetFunctionDict();
    void SetFunctionDict(ApyiDict*);
    void AddGlobal(const char*, ApyiPyPython*);
    void PushOnStack(ApyiPyPython*);
    // a
private:
    bool closureModified;
    ApyiDict *FunctionGlobals;
    ApyiPy_Tuple *FunctionClosure;
    //PyObject* FCELL;
};

#endif /* PYFUNCTIONAL_H */