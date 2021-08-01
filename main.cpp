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

void DestructionProcess(PyObject* targetCapsule){
    std::cout << "Capsule destructor called" << std::endl;
}

PyObject* spam_systems(PyObject* self, PyObject* args)
{
    const char* command;
    int sts;
    int otherArg;

    int *sx = new int(55);
    void* mPtr = sx;
    PyObject* mCapsule = PyCapsule_New(mPtr, "spam.wow", DestructionProcess);
    PyObject* other = nullptr;
    if(!PyArg_ParseTuple(args, "si|O", &command, &otherArg, &other))
        return NULL;


    PyObject_CallNoArgs(other);
    std::cout << command << otherArg << std::endl;
    // sts = system(command);
    ApyiPy_Int a = 15;
    std::cout << PyObject_CheckBuffer(a.GetPySelf()) << std::endl;
    return mCapsule;
}

PyMethodDef SpamMethods[6] = {
    {"system", spam_systems, METH_VARARGS, NULL},
    {"system3", spam_systems, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL},
    {NULL, NULL, 0, NULL},
    {NULL, NULL, 0, NULL},
    {NULL, NULL, 0, NULL}
};

PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",
    "Hello people",
    -1,
    SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
    PyModuleDef& currentModule = ApyiModuleResource::GetInstance().BringNext();
    std::cout << currentModule.m_name << std::endl;
    std::cout << currentModule.m_methods << std::endl;
    return PyModule_Create(&currentModule);
}

int main()
{
    ApyiConfig::GetInstance().LoadConfigFile("../config.json");
    ApyiConfig::GetInstance().ApplyConfig();
    ApyiModuleResource::GetInstance().CreateFunction("spam", "system3", spam_systems);
    //ApyiModuleResource::GetInstance().CreateFunction("ffds", "myname", spam_systems);
    ApyiModuleResource::GetInstance().RandomShit();

    
    //PyImport_AppendInittab("spam", apM.PyInit_spam);
    //PyImport_AppendInittab("spam", myTarget(&apM, &ApyiModuleContent::PyInit_spam));
    //PyImport_AppendInittab("spam", mFunc.target());
    PyImport_AppendInittab("spam", PyInit_spam);
    Py_Initialize();


    std::cout << "--------------------" << std::endl;

    ApyiImportObject mPort = ApyiImportManager::GetInstance().ImportModule("sak", false);
    ApyiPy_Function mFunction = mPort.GetFunction("selamshit");
    ApyiDict& mDict = mFunction.GetFunctionDict();
    ApyiPyString mString;
    mString = "lelel";
    mDict.SetItem("hellboy", &mString);
    mFunction();
    //void* vp = PyCapsule_GetContext(result);

    //std::cout << result << std::endl;
    //ApyiConfig::GetInstance().AfterInit();

    Py_FinalizeEx();
    getchar();
    return 0;
}
