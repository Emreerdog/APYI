#ifndef APYI_MODULERESOURCES_H
#define APYI_MODULERESOURCES_H

#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>
#include <AdvancedPythonInterface/PyTypes/PyPython.h>
#include <unordered_map>
#include <vector>
#include <string>

#define APYI_MMETHOD_COUNT 8

typedef PyObject* (*methodPtr)(PyObject*, PyObject*);

struct MethodStructure{
    PyMethodDef* m_method;
    unsigned int currentIndex;
    unsigned int resizeVal;
    std::string methName;
};

class ApyiModuleResource : public UErSingleton<ApyiModuleResource> {
public:
    ApyiModuleResource();
    void CreateFunction(const char* targetModule, const char* methodName, methodPtr mpr);
    void RegisterAll();
    void InitializeAll();
    std::vector<PyModuleDef>& GetCustomModules();
    PyModuleDef& BringNext(); // For important purposes
private:
    void MapModules();
    std::unordered_map<const char*, MethodStructure> moduleMethodMap;
    std::vector<PyModuleDef> createdModules;
};

#endif /* APYI_MODULERESOURCES_H */