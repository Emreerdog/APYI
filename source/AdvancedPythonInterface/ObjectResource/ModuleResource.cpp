#include <AdvancedPythonInterface/ObjectResource/ModuleResource.h>
#include <iostream>
#include <algorithm>

ApyiModuleResource::ApyiModuleResource()
{
    MethodCapacity = 5;
}

void ApyiModuleResource::CreateFunction(const std::string& targetModule, const char* methodName, methodPtr mpr)
{
    if(moduleMethodMap.find(targetModule) == moduleMethodMap.end())
    {
        // Not found
        PyMethodDef* methodPool = (PyMethodDef*)malloc(sizeof(PyMethodDef) * MethodCapacity);
        unsigned int _currentIndex = 0;
        MethodStructure MS = {methodPool, _currentIndex};
        MS.methName = methodName;
        MS.currentIndex = _currentIndex;
        MS.resizeVal = MethodCapacity;
        methodPool[_currentIndex] = { methodName, mpr, METH_VARARGS, NULL };
        MS.currentIndex++;
        moduleMethodMap.insert(std::make_pair(targetModule, MS));
        return;
    }
    
    MethodStructure& MS = moduleMethodMap[targetModule];
    PyMethodDef* methodPool = MS.m_method;
    if(MS.currentIndex == MS.resizeVal)
    {
        MS.resizeVal += MethodCapacity;
        methodPool = (PyMethodDef*)realloc(methodPool, MS.resizeVal);
    }
    MS.methName = methodName;
    methodPool[MS.currentIndex] = { methodName, mpr, METH_VARARGS, NULL };
    MS.currentIndex++;

    //createdMethods[customMethodCount] = {methodName.c_str(), mpr, METH_VARARGS, NULL};
}

void ApyiModuleResource::RandomShit()
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
        modName = iter.first;
        std::cout << MS.methName << std::endl;
        std::cout << workMethod->ml_name << std::endl;
        createdModules.push_back({PyModuleDef_HEAD_INIT, modName.c_str(), "ss", -1, workMethod});
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
    std::cout << mIndex << std::endl;
    return createdModules[mIndex];
    
}