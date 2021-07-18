#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>
#include <iostream>

int main()
{
    Py_Initialize();
    
    Py_FinalizeEx();
    getchar();
    return 0;
}