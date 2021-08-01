#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>

ApyiImportObject::ApyiImportObject()
{
    
}

ApyiImportObject::ApyiImportObject(const ApyiImportObject& other)
{
    selfPy = other.selfPy;
    selfName = other.selfName;
}

ApyiImportObject::~ApyiImportObject()
{
    Py_CLEAR(selfPy);
}

ApyiPy_Function ApyiImportObject::GetFunction(const std::string& funcName)
{
    const char* _funcName = funcName.c_str();
    PyObject* requestedFunction = PyObject_GetAttrString(selfPy, _funcName);
    if(requestedFunction == NULL)
    {
        // Given symbol doesn't exist
        // TODO
        // Give reasonable info

        return ApyiPy_Function();
    }

    if(PyFunction_Check(requestedFunction) == NULL)
    {
        // Given symbol is not a function
        Py_CLEAR(requestedFunction);
        
        return ApyiPy_Function();
    }

    ApyiPy_Function resultantFunc;
    ApyiDict functionDict;
    functionDict.SetPyFlag(ApyiPyFlag::APYI_NOT_RELEASE);
    functionDict.SetPySelf(PyFunction_GetGlobals(requestedFunction));
    resultantFunc.SetPySelf(requestedFunction);
    resultantFunc.SetFunctionDict(functionDict);
    resultantFunc.SetPyFlag(ApyiPyFlag::APYI_NOT_RELEASE);
    resultantFunc.SetPyName(_funcName);

    return resultantFunc;
}

ApyiDict* ApyiImportObject::GetDict()
{
    return nullptr;
}

ApyiPyPython* ApyiImportObject::GetVariable(const std::string& varName)
{
    return nullptr;
}