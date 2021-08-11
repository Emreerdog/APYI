#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>
#include <AdvancedPythonInterface/PyTypes/PyTuple.h>
#include <AdvancedPythonInterface/Logging/Logger.h>

ApyiPy_Function::ApyiPy_Function()
{
    FunctionGlobals = new ApyiDict();
}

ApyiPy_Function::ApyiPy_Function(PyObject* other)
{
    if(PyFunction_Check(other) == NULL)
    {
        selfPy = nullptr;
        APYI_LOG(ApyiLogging::APYI_OUT_CONSOLE, ApyiLogging::kError, "Given object is not a function type");
    }
    selfPy = other;
    PyObject* randomNumber = PyLong_FromLong(44);
    PyObject* mCell = PyCell_New(randomNumber);
    FunctionClosure = new ApyiPy_Tuple(1);
    
    //PyFunction_SetClosure(selfPy, cellTuple);
    //FunctionClosure = new ApyiPy_Tuple(PyFunction_GetClosure(lul));
    closureModified = false;
}

ApyiPy_Function::ApyiPy_Function(const ApyiPy_Function& other)
{
    selfPy = other.selfPy;
    selfName = other.selfName;
    FunctionGlobals = other.FunctionGlobals;
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

PyObject* ApyiPy_Function::Call(ApyiPyPython* arg)
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

void ApyiPy_Function::AddGlobal(const char* key, ApyiPyPython* targetGlobal)
{
    FunctionGlobals->SetItem(key, targetGlobal);
}

void ApyiPy_Function::PushOnStack(ApyiPyPython* obj)
{

}

