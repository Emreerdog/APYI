#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>
#include <json/json.h>
#include <typeinfo>
#include <iostream>

int main()
{
    Py_Initialize();
    ApyiImportObject* importedVal = ApyiImportManager::GetInstance().ImportModule("math", false);
    std::cout << typeid(importedVal->GetPySelf()).name() << std::endl;
    Json::Value a;
    a[0]["hello"] = "asasd";

    std::cout << typeid(a[0]["hello"].asCString()).name() << std::endl;
    Py_FinalizeEx();
    getchar();
    return 0;
}