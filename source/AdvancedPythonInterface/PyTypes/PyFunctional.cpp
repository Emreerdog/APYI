#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>
#include <AdvancedPythonInterface/PyTypes/PyTuple.h>

ApyiPy_Function::ApyiPy_Function()
{
    FunctionGlobals = nullptr;
}

PyObject* ApyiPy_Function::CallFunc()
{
    PyObject* returnVal = PyObject_CallNoArgs(selfPy);
    if(returnVal == NULL)
    {
        return nullptr;
    }
    return returnVal;
}

ApyiDict* ApyiPy_Function::GetFunctionDict()
{
    if(FunctionGlobals == NULL)
    {
        FunctionGlobals->SetPySelf(PyFunction_GetGlobals(selfPy));
    }
    return FunctionGlobals;
}

void ApyiPy_Function::SetFunctionDict(ApyiDict* newDict)
{
    Py_CLEAR(FunctionGlobals);
    FunctionGlobals = newDict;
}

PyObject* ApyiPy_Function::CallArgs(ApyiPy_Tuple* fArguments)
{
    PyObject* returnVal = PyObject_CallObject(selfPy, fArguments->GetPySelf());
    if(returnVal == NULL)
    {
        return nullptr;
    }
    return returnVal;
}

void ApyiPy_Function::AddGlobal(const std::string& key, ApyiPyPython* targetGlobal)
{
    FunctionGlobals->SetItem(key, targetGlobal);
}


