#include <AdvancedPythonInterface/PyTypes/PyPython.h>

ApyiPyPython::ApyiPyPython()
{
    selfPy = nullptr;
}

ApyiPyPython::~ApyiPyPython()
{
    Py_CLEAR(selfPy);
}

PApyiCallData ApyiPyPython::GetCallData() const {
    return m_callData;
}

PyObject* ApyiPyPython::GetPySelf() const{
    return selfPy;
}

void* ApyiPyPython::Convert_C(){
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

void ApyiPyPython::IncreaseReference()
{
    Py_INCREF(selfPy);
}

void ApyiPyPython::DecreaseReference()
{
    Py_DECREF(selfPy);
}