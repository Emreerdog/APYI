#include <APYI/PyTypes/PyInt.h>
#include <APYI/PyTypes/PyTuple.h>
#include <APYI/PyTypes/PyImportObject.h>
#include <APYI/Importer/ImportManager.h>
#include <APYI/PyTypes/PyFunctional.h>
#include <APYI/PyTypes/PyString.h>
#include <APYI/PyTypes/PyDict.h>
#include <APYI/FileSystem/PathTraits.h>
#include <APYI/Configurator/Config.h>
#include <APYI/ObjectUtils/StringUtils.h>
#include <APYI/ObjectResource/ModuleResource.h>
#include <APYI/Logging/Logger.h>
#include <APYI/FileSystem/FileSystem.h>
#include <APYI/FileSystem/PathTraits.h>
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
    
    ApyiPy_String mstr = "this is cool";
    mstr.SetPyFlag(ApyiPyFlag::APYI_NOT_RELEASE);
    return mstr.GetPySelf();
}

PyObject* hello_people(PyObject* self, PyObject* args)
{
    Py_CLEAR(args);
    ApyiPy_Int m_int = 44;
    m_int.SetPyFlag(ApyiPyFlag::APYI_NOT_RELEASE);
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
    PyErr_Print();
    PyObject* ress = importedFunction->Call();
    
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
