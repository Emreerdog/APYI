#include <AdvancedPythonInterface/PyTypes/PyPython.h>

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