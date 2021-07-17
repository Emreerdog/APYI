#ifndef PYPYTHON_H
#define PYPYTHON_H

#include <AdvancedPythonInterface/PyTypes/PythonBase.h>

class ApyiPyPython : public ApyiPythonBase{
public:
    virtual PApyiCallData GetCallData() const override;
    virtual PyObject* GetPySelf() const override;
    virtual void* Convert_C(); 
    virtual void SetPySelf(PyObject*) override;

protected:
};

#endif /* PYPYTHON_H */