#ifndef APYI_MODULERESOURCES_H
#define APYI_MODULERESOURCES_H

#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>
#include <AdvancedPythonInterface/PyTypes/PyPython.h>
#include <unordered_map>
#include <vector>
#include <string>

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
    void CreateFunction(const std::string& targetModule, const char* methodName, methodPtr mpr);
    void RandomShit();
    std::vector<PyModuleDef>& GetCustomModules();
    PyModuleDef& BringNext(); // For important purposes
private:
    std::unordered_map<std::string, MethodStructure> moduleMethodMap;
    std::vector<PyModuleDef> createdModules;
    unsigned int MethodCapacity;
    std::string modName;
};

#endif /* APYI_MODULERESOURCES_H */