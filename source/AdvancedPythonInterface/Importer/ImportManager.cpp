#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/ObjectResource/PythonDistributor.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>

ApyiImportManager::ApyiImportManager()
{

}

ApyiImportObject* ApyiImportManager::ImportModule(const std::string& moduleName, bool bIsDistributed=false)
{
    const char* _mName = moduleName.c_str();
    PyObject* importedObject = PyImport_ImportModule(_mName);
    if(importedObject == NULL)
    {
        return nullptr;
    }

    ApyiImportObject* resultantImObject = new ApyiImportObject();
    resultantImObject->SetPySelf(importedObject);
    resultantImObject->SetPyName(_mName);
    if(bIsDistributed)
    {
        ApyiDistributor::GetInstance().DistributeModule(resultantImObject, false);
    }

    return resultantImObject;
}