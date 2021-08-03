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

int main()
{
    ApyiConfig::GetInstance().LoadConfigFile("../config.json");
    ApyiConfig::GetInstance().ApplyConfig();
    ApyiModuleResource::GetInstance().CreateFunction("spam", "system3", spam_systems);
    ApyiModuleResource::GetInstance().CreateFunction("selamke", "hello", hello_people);

    //ApyiModuleResource::GetInstance().CreateFunction("ffds", "myname", spam_systems);
    ApyiModuleResource::GetInstance().RegisterAll();

    
    //PyImport_AppendInittab("spam", apM.PyInit_spam);
    //PyImport_AppendInittab("spam", myTarget(&apM, &ApyiModuleContent::PyInit_spam));
    //PyImport_AppendInittab("spam", mFunc.target());
    //PyImport_AppendInittab("spam", PyInit_spam);
    Py_Initialize();

    std::cout << "--------------------" << std::endl;

    ApyiImportObject mPort = ApyiImportManager::GetInstance().ImportModule("sak", false);
    ApyiPy_Function mFunction = mPort.GetFunction("selamshit");
    ApyiDict& mDict = mFunction.GetFunctionDict();
    ApyiPy_Tuple m_tuple = ApyiPy_Tuple(2);
    ApyiPyString mString = "TEST STRING 1";
    ApyiPyString mString2 = "TEST STRING 2";
    m_tuple.AddItem(&mString);
    m_tuple.AddItem(&mString2);

    //mDict.SetItem("hellboy", &m_tuple);
    mFunction(&m_tuple);
    //void* vp = PyCapsule_GetContext(result);

    //std::cout << result << std::endl;
    //ApyiConfig::GetInstance().AfterInit();

    Py_FinalizeEx();
    getchar();
    return 0;
}
