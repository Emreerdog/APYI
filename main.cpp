#include <AdvancedPythonInterface/PyTypes/PyInt.h>
#include <AdvancedPythonInterface/PyTypes/PyTuple.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <AdvancedPythonInterface/Configurator/Config.h>
#include <iostream>

int main()
{
    ApyiConfig::GetInstance().LoadConfigFile("../config.json");
    ApyiConfig::GetInstance().ApplyConfig();
    Py_Initialize();
    //ApyiImportManager::GetInstance().ImportModule("bumz", false);
    // ApyiPy_Int* mInt = new ApyiPy_Int(44);
    // ApyiPy_Int* mInt2 = new ApyiPy_Int(32);
    // ApyiPy_Int* mInt3 = new ApyiPy_Int(65);
    std::wcout << Py_GetPath() << std::endl;
    // ApyiPy_Tuple* mTuple = new ApyiPy_Tuple(3);
    // mTuple->AddItem(mInt);
    // mTuple->AddItem(mInt2);
    // mTuple->AddItem(mInt3);
    // ApyiImportObject* importedModule = ApyiImportManager::GetInstance().ImportModule("bumz", false);
    
    // ApyiPy_Function* importedFunction = importedModule->GetFunction("myFunction");
    // importedFunction->CallArgs(mTuple);

    // delete mInt;

    Py_FinalizeEx();
    getchar();
    return 0;
}
