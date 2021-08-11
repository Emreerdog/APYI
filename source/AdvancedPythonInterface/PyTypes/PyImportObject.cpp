#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/Logging/Logger.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>
#include <iostream>

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

ApyiPy_Function* ApyiImportObject::GetFunction(const char* funcName)
{
    PyObject* requestedFunction = PyObject_GetAttrString(selfPy, funcName);
    if(requestedFunction == NULL)
    {
        // Given symbol doesn't exist
        // TODO
        // Give reasonable info
        PyErr_Print();
        return nullptr;
    }

    if(!(PyFunction_Check(requestedFunction)) || !(PyCallable_Check(requestedFunction)))
    {
        // Given symbol is not a function
        Py_CLEAR(requestedFunction);
        APYI_LOG(ApyiLogging::APYI_OUT_CONSOLE, ApyiLogging::kError, "Given value %s is not a callable type", funcName);
        std::cout << "Given Value (" << funcName << ") " << "is not a function" << std::endl;
        return nullptr;
    }
    PyObject* funcDict = PyFunction_GetGlobals(requestedFunction);
    ApyiPy_Function *resultantFunc = new ApyiPy_Function(requestedFunction);
    ApyiDict *functionDict = new ApyiDict(funcDict);
    resultantFunc->SetFunctionDict(functionDict);
    resultantFunc->SetPyName(funcName);

    return resultantFunc;
}

PyObject* ApyiImportObject::GetAttribute(const char* varName)
{
    PyObject* requestedAttribute = PyObject_GetAttrString(selfPy, varName);
    if(requestedAttribute == nullptr)
    {
        APYI_LOG(ApyiLogging::APYI_OUT_CONSOLE, ApyiLogging::kError, "Given attribute %s is not a callable type", varName);
        return nullptr;
    }
    return requestedAttribute;
}