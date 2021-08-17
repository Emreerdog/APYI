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

template <typename R, typename ... Types> 
constexpr std::integral_constant<unsigned, sizeof ...(Types)> getArgumentCount( R(*f)(Types ...))
{
   return std::integral_constant<unsigned, sizeof ...(Types)>{};
}

int main()
{
    ApyiConfig::GetInstance().LoadConfigFile("../config.json");
    ApyiConfig::GetInstance().ApplyConfig();
    //ApyiModuleResource::GetInstance().CreateFunction("spam", "system3", spam_systems);
    //ApyiModuleResource::GetInstance().CreateFunction("selamke", "hello", hello_people);

    //ApyiModuleResource::GetInstance().CreateFunction("ffds", "myname", spam_systems);
    //ApyiModuleResource::GetInstance().RegisterAll();
    
    Py_Initialize();
    
    ApyiPy_String myString = "hello world";
    ApyiPy_Long mLong = 44;
    ApyiPy_Float mFloat = 55.4;
    
    ApyiImportObject* imp1 = ApyiImportManager::GetInstance().ImportModule("sak");
    ApyiPy_Function* getFunc = imp1->GetFunction("wow");
    PyObject* normalObject = getFunc->GetPySelf();
    PyObject* functionCode = PyFunction_GetCode(normalObject);
    std::cout << PyBytes_Check(functionCode) << std::endl;

    Py_FinalizeEx();
    getchar();
    return 0;
}
