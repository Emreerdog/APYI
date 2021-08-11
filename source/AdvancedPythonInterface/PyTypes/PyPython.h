#ifndef PYPYTHON_H
#define PYPYTHON_H

#include <AdvancedPythonInterface/PyTypes/PythonBase.h>

class ApyiPyPython : public ApyiPythonBase{
public:
    ApyiPyPython();
    ~ApyiPyPython();
    virtual PApyiCallData GetCallData() const override;
    virtual void SetCallData(PApyiCallData&) override;
    virtual PyObject* GetPySelf() const override;
    virtual void* RawData(); 
    virtual void SetPySelf(PyObject*) override;
    virtual std::string GetPyName() override;
    virtual void SetPyName(const std::string&) override;
    virtual void SetPyFlag(const ApyiPyFlag&) override;
    virtual void IncreaseReference() override;
    virtual void DecreaseReference() override;
    
protected:
};

#endif /* PYPYTHON_H */