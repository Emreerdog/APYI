#ifndef PYFUNCTIONAL_H
#define PYFUNCTIONAL_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>

class ApyiPy_Tuple;

class ApyiPy_Function : public ApyiPyPython{
public:
    ApyiPy_Function();
    ApyiPy_Function(const ApyiPy_Function&);
    ~ApyiPy_Function();
    PyObject* operator()();
    PyObject* operator()(ApyiPyPython*);
    PyObject* operator()(ApyiPy_Tuple*);

    PyObject* CallFunc();
    PyObject* CallOneArg(ApyiPyPython*);
    PyObject* CallArgs(ApyiPy_Tuple*);
    ApyiDict& GetFunctionDict();
    void SetFunctionDict(const ApyiDict&);
    void AddGlobal(const std::string& , ApyiPyPython*);
    // a
private:
    ApyiDict FunctionGlobals;
};

#endif /* PYFUNCTIONAL_H */