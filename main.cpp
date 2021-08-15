#include <APYI/PyTypes/PyLong.h>
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

// PyObject* spam_systems(PyObject* self, PyObject* args)
// {
//     const char* command;
//     int sts;
//     int otherArg;

//     PyObject* other = nullptr;
//     if(!PyArg_ParseTuple(args, "si|O", &command, &otherArg, &other))
//         return NULL;


//     //PyObject_CallNoArgs(other);
//     std::cout << command << otherArg << std::endl;
//     // sts = system(command);
    
//     ApyiPy_String mstr = "this is cool";
//     mstr.SetPyFlag(ApyiPyFlag::APYI_NOT_RELEASE);
//     return mstr.GetPySelf();
// }


int main()
{
    ApyiConfig::GetInstance().LoadConfigFile("../config.json");
    ApyiConfig::GetInstance().ApplyConfig();
    //ApyiModuleResource::GetInstance().CreateFunction("spam", "system3", spam_systems);
    //ApyiModuleResource::GetInstance().CreateFunction("selamke", "hello", hello_people);

    //ApyiModuleResource::GetInstance().CreateFunction("ffds", "myname", spam_systems);
    //ApyiModuleResource::GetInstance().RegisterAll();
    
    Py_Initialize();
    ApyiImportObject* mPort = ApyiImportManager::GetInstance().ImportModule("sak");
    ApyiPy_String a = "hello";
    ApyiPy_String b = "zuz";
    b = a;
    std::cout << a << std::endl;
    ApyiPy_Long mLong = 11;
    ApyiPy_Long zzLong = 55;
    PyObject_SetAttrString(mLong.GetPySelf(), "someattr", PyLong_FromLong(22));
    ApyiPy_Tuple functionArguments = ApyiPy_Tuple(2);
    functionArguments.AddItem(&b);
    functionArguments.AddItem(&mLong);
    ApyiPy_Function* tempFunction = mPort->GetFunction("wow");
    for(int i = 0; i < 10; i++)
    {
        tempFunction->Call(&functionArguments);
    }
    std::cout << functionArguments.GetSize() << std::endl;
    std::cout << "----" << std::endl;
    std::cout << a << std::endl;
    std::cout << mLong << std::endl;

    Py_FinalizeEx();
    getchar();
    return 0;
}
