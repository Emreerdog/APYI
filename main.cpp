#include <AdvancedPythonInterface/FileSystem/FileSystem.h>
#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>

int main()
{
    Py_Initialize();
    ApyiImportObject* impObj = ApyiImportManager::GetInstance().ImportModule("bumz");
    ApyiPy_Function* functionObject = impObj->GetFunction("OnPageLoad");
    functionObject->CallFunc();

    Py_FinalizeEx();
    getchar();
    return 0;
}