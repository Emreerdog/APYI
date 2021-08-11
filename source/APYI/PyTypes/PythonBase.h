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
#include <APYI/PyTypes/CallData.h>

enum ApyiPyFlag{
  APYI_NOT_RELEASE,
  APYI_RELEASE
};

class ApyiPythonBase{
public:
    virtual PApyiCallData GetCallData() const = 0;
    virtual void SetCallData(PApyiCallData&) = 0;
    virtual PyObject* GetPySelf() const = 0;
    virtual void SetPySelf(PyObject*) = 0;
    virtual std::string GetPyName() = 0;
    virtual void SetPyName(const std::string&) = 0;
    virtual void SetPyFlag(const ApyiPyFlag&) = 0;
    virtual void IncreaseReference() = 0;
    virtual void DecreaseReference() = 0;
    
protected:
    PApyiCallData m_callData;
    PyObject* selfPy;
    std::string selfName;
    ApyiPyFlag EPF;
};

#endif /* PYPYTHONBASE_H */