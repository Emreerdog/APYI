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
#include <AdvancedPythonInterface/ObjectResource/ModuleResource.h>
#include <AdvancedPythonInterface/Logging/Logger.h>
#include <AdvancedPythonInterface/FileSystem/FileSystem.h>
#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <stdlib.h>
#include <functional>

PyObject* spam_systems(PyObject* self, PyObject* args)
{
    const char* command;
    int sts;
    int otherArg;

    PyObject* other = nullptr;
    if(!PyArg_ParseTuple(args, "si|O", &command, &otherArg, &other))
        return NULL;


    //PyObject_CallNoArgs(other);
    std::cout << command << otherArg << std::endl;
    // sts = system(command);
    
    ApyiPyString *testString = new ApyiPyString("this is good");
    
    return testString->GetPySelf();
}

PyObject* hello_people(PyObject* self, PyObject* args)
{
    std::cout << "It works" << std::endl;
    ApyiPy_Int m_int = 44;
    return m_int.GetPySelf(); 
}

void DestroyCapsule(PyObject* Cap)
{

}

int main()
{
    ApyiConfig::GetInstance().LoadConfigFile("../config.json");
    ApyiConfig::GetInstance().ApplyConfig();
    ApyiModuleResource::GetInstance().CreateFunction("spam", "system3", spam_systems);
    ApyiModuleResource::GetInstance().CreateFunction("selamke", "hello", hello_people);

    //ApyiModuleResource::GetInstance().CreateFunction("ffds", "myname", spam_systems);
    ApyiModuleResource::GetInstance().RegisterAll();
    
    Py_Initialize();
    ApyiModuleResource::GetInstance().InitializeAll();
    ApyiImportObject* mPort = ApyiImportManager::GetInstance().ImportModule("sak", false);
    ApyiPy_Function* importedFunction = mPort->GetFunction("selamshit");
    importedFunction->Call();
    ApyiImportManager::GetInstance().ImportModule("sak", false);
    ApyiImportManager::GetInstance().ImportModule("myModule", false);

    
    //ApyiFileSystem::ErCreateDirectory("ezgininKlasor");
    //ApyiPathTraits::EGetCurrentDir();
    // while(1)
    // {
    //     ApyiPy_Tuple mTuple = ApyiPy_Tuple(3);
    //     ApyiPyString checkStr = "Hello world";
    //     ApyiPyString checkStr2 = "hello everyone";
    //     ApyiPyString checkStr3 = "Hello life";
    //     mTuple.AddItem(&checkStr);
    //     mTuple.AddItem(&checkStr2);
    //     mTuple.AddItem(&checkStr3);
    //     importedFunction->Call(&mTuple);
    //     std::cout << checkStr << std::endl;
    //     std::cout << checkStr2 << std::endl;
    //     std::cout << checkStr3 << std::endl;
        
    // }

    Py_FinalizeEx();
    getchar();
    return 0;
}
