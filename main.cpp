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
#include <iostream>
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

    ApyiImportManager& iMng = ApyiImportManager::GetInstance();
    ApyiImportObject resultImport = iMng.ImportModule("sak", true);
    ApyiPy_Function requestedFunction = resultImport.GetFunction("listVals");


    std::cout << "--------------------" << std::endl;

    ApyiPyString m_string = "Hello world";
    ApyiPy_Int mVal = 43;
    ApyiPyString m_string2 = "lol";
    ApyiPy_Tuple funcArgs = ApyiPy_Tuple(3);
    funcArgs.AddItem(&m_string);
    funcArgs.AddItem(&mVal);
    funcArgs.AddItem(&m_string2);

    std::string *testVal = new std::string("lelel");
    void* raw = testVal;
    

    PyObject* myCapsule = PyCapsule_New(raw, "test_capsule", DestroyCapsule);
    void* cContext =  PyCapsule_GetPointer(myCapsule, "test_capsule");
    std::string* testVal2 = (std::string*)(cContext);
    std::cout << *testVal2 << std::endl;
    requestedFunction(&funcArgs);
    //std::cout << resultString << std::endl;
    //std::cout << m_string << std::endl;
    //mDict.SetItem("hellboy", &m_tuple);
    //mFunction(&m_tuple);
    //void* vp = PyCapsule_GetContext(result);

    //std::cout << result << std::endl;
    //ApyiConfig::GetInstance().AfterInit();

    Py_FinalizeEx();
    getchar();
    return 0;
}
