#include <APYI/ObjectResource/ModuleResource.h>
#include <APYI/Importer/ImportManager.h>
#include <iostream>
#include <algorithm>

PyMODINIT_FUNC ModuleInitCallback(void)
{
    PyModuleDef& currentModule = ApyiModuleResource::GetInstance().BringNext();
    std::cout << "Module imported" << std::endl;
    return PyModule_Create(&currentModule);
}

ApyiModuleResource::ApyiModuleResource()
{
    
}

void ApyiModuleResource::CreateFunction(const char* targetModule, const char* methodName, methodPtr mpr)
{
    if(moduleMethodMap.find(targetModule) == moduleMethodMap.end())
    {
        // Not found
        PyMethodDef* methodPool = (PyMethodDef*)malloc(sizeof(PyMethodDef) * APYI_MMETHOD_COUNT);
        unsigned int _currentIndex = 0;
        MethodStructure MS = {methodPool, _currentIndex};
        MS.methName = methodName;
        MS.currentIndex = _currentIndex;
        MS.resizeVal = APYI_MMETHOD_COUNT;
        methodPool[_currentIndex] = { methodName, mpr, METH_VARARGS, NULL };
        MS.currentIndex++;
        
        moduleMethodMap.insert(std::make_pair(targetModule, MS));
        return;
    }
    
    MethodStructure& MS = moduleMethodMap[targetModule];
    PyMethodDef* methodPool = MS.m_method;
    if(MS.currentIndex == MS.resizeVal)
    {
        MS.resizeVal += APYI_MMETHOD_COUNT;
        methodPool = (PyMethodDef*)realloc(methodPool, MS.resizeVal);
    }
    MS.methName = methodName;
    methodPool[MS.currentIndex] = { methodName, mpr, METH_VARARGS, NULL };
    MS.currentIndex++;

    //createdMethods[customMethodCount] = {methodName.c_str(), mpr, METH_VARARGS, NULL};
}

void ApyiModuleResource::MapModules()
{
    if(moduleMethodMap.size() == 0)
    {
        return;
    }
    for(auto iter : moduleMethodMap)
    {
        MethodStructure &MS = iter.second;
        PyMethodDef* workMethod = MS.m_method;
        workMethod[MS.currentIndex] = {NULL, NULL, 0, NULL};
        const char* modName = iter.first;
        //std::cout << MS.methName << std::endl;
        //std::cout << workMethod->ml_name << std::endl;
        //std::cout << modName.c_str() << std::endl;
        
        createdModules.push_back({PyModuleDef_HEAD_INIT, modName, "ss", -1, workMethod});
    }
}

void ApyiModuleResource::RegisterAll()
{
    MapModules();
    for(int i = 0; i < createdModules.size(); i++)
    {
        //const char* mm_name = createdModules[i].m_name;
        //std::cout << mm_name << std::endl;
        const char* mm_name = createdModules[i].m_name;
        PyImport_AppendInittab(mm_name, ModuleInitCallback);
    }
}

void ApyiModuleResource::InitializeAll()
{
    for(auto eachModule : moduleMethodMap)
    {
        ApyiImportObject* mportObj = ApyiImportManager::GetInstance().ImportModule(eachModule.first);
        delete mportObj;
    }
}

std::vector<PyModuleDef>& ApyiModuleResource::GetCustomModules()
{
    return createdModules;
}

PyModuleDef& ApyiModuleResource::BringNext()
{
    static int mIndex = -1;
    mIndex++;
    return createdModules[mIndex];
    
}