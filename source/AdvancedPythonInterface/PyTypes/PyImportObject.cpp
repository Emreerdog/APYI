#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>

ApyiImportObject::ApyiImportObject()
{
    
}

ApyiImportObject::~ApyiImportObject()
{
    Py_CLEAR(selfPy);
}

ApyiPy_Function* ApyiImportObject::GetFunction(const std::string& funcName)
{
    const char* _funcName = funcName.c_str();
    PyObject* requestedFunction = PyObject_GetAttrString(selfPy, _funcName);
    if(requestedFunction == NULL)
    {
        // Given symbol doesn't exist
        // TODO
        // Give reasonable info

        return nullptr;
    }

    if(PyFunction_Check(requestedFunction) == NULL)
    {
        // Given symbol is not a function
        Py_CLEAR(requestedFunction);
        
        return nullptr;
    }

    ApyiPy_Function* resultantFunc = new ApyiPy_Function();
    ApyiDict* functionDict = new ApyiDict(false);
    functionDict->SetPySelf(PyFunction_GetGlobals(requestedFunction));
    resultantFunc->SetPySelf(requestedFunction);
    resultantFunc->SetFunctionDict(functionDict);
    resultantFunc->SetPyName(_funcName);

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