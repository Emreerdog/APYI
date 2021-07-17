#ifdef _DEBUG
  #undef _DEBUG
  #include <Python.h>
  #define _DEBUG
#else
  #include <Python.h>
#endif

#ifndef PYPYTHONBASE_H
#define PYPYTHONBASE_H

#include <string>
#include <AdvancedPythonInterface/PyTypes/CallData.h>

class ApyiPythonBase{
public:
    virtual PApyiCallData GetCallData() const = 0;
    virtual PyObject* GetPySelf() const = 0;
    virtual void SetPySelf(PyObject*) = 0;
protected:
    PApyiCallData m_callData;
    PyObject* selfPy;
};

#endif /* PYPYTHONBASE_H */