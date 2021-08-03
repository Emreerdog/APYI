#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>
#include <AdvancedPythonInterface/PyTypes/PyTuple.h>

ApyiPy_Function::ApyiPy_Function()
{
    
}

ApyiPy_Function::ApyiPy_Function(const ApyiPy_Function& other)
{
    selfPy = other.selfPy;
    selfName = other.selfName;
    FunctionGlobals = other.FunctionGlobals;
}

ApyiPy_Function::~ApyiPy_Function()
{
    
}

PyObject* ApyiPy_Function::operator()()
{
    PyObject* returnVal = PyObject_CallNoArgs(selfPy);
    if(PyErr_Occurred())
    {
        PyErr_Print();
    }
    if(returnVal == NULL)
    {
        return nullptr;
    }
    return returnVal;
}

PyObject* ApyiPy_Function::operator()(ApyiPyPython* arg)
{
    PyObject* argSelf = arg->GetPySelf();
    return PyObject_CallOneArg(selfPy, argSelf);
}

PyObject* ApyiPy_Function::operator()(ApyiPy_Tuple* args)
{
    PyObject* returnVal = PyObject_CallObject(selfPy, args->GetPySelf());
    if(PyErr_Occurred())
    {
        PyErr_Print();
    }
    return returnVal;
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

PyObject* ApyiPy_Function::CallOneArg(ApyiPyPython* arg)
{
    PyObject* argSelf = arg->GetPySelf();
    return PyObject_CallOneArg(selfPy, argSelf);
}

ApyiDict& ApyiPy_Function::GetFunctionDict()
{
    return FunctionGlobals;
}

void ApyiPy_Function::SetFunctionDict(const ApyiDict& newDict)
{
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
    FunctionGlobals.SetItem(key, targetGlobal);
}


