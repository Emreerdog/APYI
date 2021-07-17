#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>

ApyiPy_Function::ApyiPy_Function()
{
    functionName = "";
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

void ApyiPy_Function::SetFunctionName(const std::string& fName)
{
    functionName = fName;
}

ApyiDict* ApyiPy_Function::GetFunctionDict()
{
    return FunctionGlobals;
}

void ApyiPy_Function::SetFunctionDict(ApyiDict* newDict)
{
    Py_CLEAR(FunctionGlobals);
    FunctionGlobals = newDict;
}

void ApyiPy_Function::AddGlobal(const std::string& key, ApyiPyPython* targetGlobal)
{
    FunctionGlobals->SetItem(key, targetGlobal);
}


