#include <APYI/PyTypes/PyFunctional.h>
#include <APYI/PyTypes/PyDict.h>
#include <APYI/PyTypes/PyTuple.h>
#include <APYI/Logging/Logger.h>

ApyiPy_Function::ApyiPy_Function()
{
    
}

ApyiPy_Function::ApyiPy_Function(PyObject* other)
{
    if(PyFunction_Check(other) == NULL)
    {
        selfPy = nullptr;
        APYI_LOG(ApyiLogging::APYI_OUT_CONSOLE, ApyiLogging::kError, "Given object is not a function type");
    }
    if(selfPy != NULL)
    {
        Py_CLEAR(selfPy);
        delete FunctionGlobals;
    }
    selfPy = other;
    FunctionGlobals = new ApyiDict(PyFunction_GetGlobals(selfPy));
}

ApyiPy_Function::ApyiPy_Function(const ApyiPy_Function& other)
{
    if(selfPy != NULL)
    {
        Py_CLEAR(selfPy);
        delete FunctionGlobals;
    }
    PyObject* otherCode = PyFunction_GetCode(other.selfPy);
    PyObject* _fGlobals = PyFunction_GetGlobals(other.selfPy);
    PyObject* resultCopy = PyFunction_New(otherCode, _fGlobals);
    PyObject* resultGlobals = PyFunction_GetGlobals(resultCopy); // Bringing new globals _fGlobals belong to old guy
    selfPy = resultCopy;
    selfName = other.selfName;
    FunctionGlobals = new ApyiDict(resultGlobals);
    //FunctionClosure = other.FunctionClosure;
}

ApyiPy_Function::~ApyiPy_Function()
{
    delete FunctionGlobals;
}

PyObject* ApyiPy_Function::Call()
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

PyObject* ApyiPy_Function::Call(ApyiPyPython* arg, ApyiDict* kwargs)
{
    PyObject* argSelf = arg->GetPySelf();
    //std::cout << FunctionClosure->GetSize() << std::endl;
    PyObject* returnVal = nullptr;
    if(PyTuple_Check(argSelf))
    {
        returnVal = PyObject_CallObject(selfPy, argSelf);
    }
    else{ 
        returnVal = PyObject_CallOneArg(selfPy, argSelf);  
    }
    if(PyErr_Occurred())
    {
        PyErr_Print();
    }
    return returnVal;
}



void ApyiPy_Function::SetFunctionDict(ApyiDict* newDict)
{
    FunctionGlobals = newDict;
}

ApyiDict* ApyiPy_Function::GetFunctionDict()
{
    return FunctionGlobals;
}

void ApyiPy_Function::AddGlobal(const char* key, ApyiPyPython* targetGlobal)
{
    FunctionGlobals->SetItem(key, targetGlobal);
}
