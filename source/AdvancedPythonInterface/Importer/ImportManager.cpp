#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>

ApyiImportManager::ApyiImportManager()
{

}

ApyiImportObject* ApyiImportManager::ImportModule(const std::string& moduleName)
{
    PyObject* importedObject = PyImport_ImportModule(moduleName.c_str());
    if(importedObject == NULL)
    {
        return nullptr;
    }

    ApyiImportObject* resultantImObject = new ApyiImportObject();
    resultantImObject->SetPySelf(importedObject);
    
    return resultantImObject;
}