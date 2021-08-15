#include <APYI/Importer/ImportManager.h>
#include <APYI/ObjectResource/PythonDistributor.h>
#include <APYI/PyTypes/PyImportObject.h>
#include <iostream>

ApyiImportManager::ApyiImportManager()
{

}

ApyiImportObject* ApyiImportManager::ImportModule(const char* moduleName)
{
    PyObject* importedObject = PyImport_ImportModule(moduleName);
    if(importedObject == NULL)
    {
        PyErr_Print();
        return nullptr;
    }

    ApyiImportObject *resultantImObject = new ApyiImportObject();
    resultantImObject->SetPySelf(importedObject);
    resultantImObject->SetPyName(moduleName);
    // if(bIsDistributed)
    // {
    //     ApyiDistributor::GetInstance().DistributeModule(resultantImObject);
    // }

    return resultantImObject;
}