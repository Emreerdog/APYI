#include <APYI/PyTypes/PyLong.h>
#include <APYI/PyTypes/PyTuple.h>
#include <APYI/PyTypes/PyImportObject.h>
#include <APYI/Importer/ImportManager.h>
#include <APYI/PyTypes/PyFunctional.h>
#include <APYI/PyTypes/PyString.h>
#include <APYI/PyTypes/PyDict.h>
#include <APYI/PyTypes/PyFloat.h>
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
    while(1)
    {
        ApyiPy_Long var1 = 44;
        ApyiPy_Long var2 = var1 + 32;
        var2 += 44.3;

        ApyiPy_Float var3 = "44.5";
        ApyiPy_Float var4 = 65;
        var3 /= var1;

    
        std::cout << var1 << std::endl;
        std::cout << var2 << std::endl;
        std::cout << var3 << std::endl;
        std::cout << var4 << std::endl;
    }

    Py_FinalizeEx();
    getchar();
    return 0;
}
