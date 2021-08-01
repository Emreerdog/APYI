#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/ObjectResource/PythonDistributor.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <iostream>

ApyiImportManager::ApyiImportManager()
{

}

ApyiImportObject ApyiImportManager::ImportModule(const std::string& moduleName, bool bIsDistributed=false)
{
    const char* _mName = moduleName.c_str();
    PyObject* importedObject = PyImport_ImportModule(_mName);
    if(importedObject == NULL)
    {
        PyErr_Print();
        return ApyiImportObject();
    }

    ApyiImportObject resultantImObject;
    resultantImObject.SetPySelf(importedObject);
    resultantImObject.SetPyName(_mName);
    resultantImObject.SetPyFlag(ApyiPyFlag::APYI_NOT_RELEASE);
    // if(bIsDistributed)
    // {
    //     ApyiDistributor::GetInstance().DistributeModule(resultantImObject);
    // }

    return resultantImObject;
}