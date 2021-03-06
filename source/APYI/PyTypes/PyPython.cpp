#include <APYI/PyTypes/PyPython.h>
#include <iostream>

ApyiPyPython::ApyiPyPython()
{
    selfPy = nullptr;
    EPF = ApyiPyFlag::APYI_RELEASE;
}

ApyiPyPython::~ApyiPyPython()
{
    if(EPF == ApyiPyFlag::APYI_RELEASE)
    {
        SelfClean();
    }
}

PApyiCallData ApyiPyPython::GetCallData() const {
    return m_callData;
}

void ApyiPyPython::SetCallData(PApyiCallData& target){
    m_callData = target;
}

PyObject* ApyiPyPython::GetPySelf() const{
    return selfPy;
}

void* ApyiPyPython::RawData(){
    return nullptr;
}

void ApyiPyPython::SetPySelf(PyObject* target){
    selfPy = target;
}

std::string ApyiPyPython::GetPyName(){
    return selfName;
}

void ApyiPyPython::SetPyName(const std::string& targetName)
{
    selfName = targetName;
}

void ApyiPyPython::SetPyFlag(const ApyiPyFlag& epf)
{
    EPF = epf;
}

void ApyiPyPython::IncreaseReference()
{
    Py_INCREF(selfPy);
}

void ApyiPyPython::DecreaseReference()
{
    Py_DECREF(selfPy);
}

void ApyiPyPython::SelfClean()
{
    Py_CLEAR(selfPy);
}