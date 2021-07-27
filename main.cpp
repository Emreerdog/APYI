#include <AdvancedPythonInterface/PyTypes/PyInt.h>
#include <AdvancedPythonInterface/PyTypes/PyTuple.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyString.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>
#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <AdvancedPythonInterface/Configurator/Config.h>
#include <AdvancedPythonInterface/ObjectUtils/StringUtils.h>
#include <iostream>

int main()
{
    ApyiConfig::GetInstance().LoadConfigFile("../config.json");
    ApyiConfig::GetInstance().ApplyConfig();
    Py_Initialize();
    ApyiConfig::GetInstance().AfterInit();
    ApyiPy_Int m_int = ApyiPy_Int(22);
    ApyiPy_Int m_int2 = ApyiPy_Int(42);

    ApyiPy_Int newInt = m_int + m_int2;
    
    std::cout << newInt << m_int << std::endl;
    
    //ApyiImportManager::GetInstance().ImportModule("bumz", false);
    // ApyiPy_Int* mInt = new ApyiPy_Int(44);
    // ApyiPy_Int* mInt2 = new ApyiPy_Int(32);
    // ApyiPy_Int* mInt3 = new ApyiPy_Int(65);
    

    Py_FinalizeEx();
    getchar();
    return 0;
}
