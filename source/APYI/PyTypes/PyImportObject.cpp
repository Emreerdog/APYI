#include <APYI/PyTypes/PyImportObject.h>
#include <APYI/PyTypes/PyFunctional.h>
#include <APYI/Logging/Logger.h>
#include <APYI/PyTypes/PyDict.h>
#include <iostream>

ApyiImportObject::ApyiImportObject()
{
    
}

ApyiImportObject::ApyiImportObject(PyObject* other)
{
    
}

ApyiImportObject::ApyiImportObject(const ApyiImportObject& other)
{
    PyObject* moduleName = PyModule_GetNameObject(other.selfPy);
    selfPy = PyModule_NewObject(moduleName);
    selfName = other.selfName;
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
    ApyiPy_Function *resultantFunc = new ApyiPy_Function(requestedFunction);
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