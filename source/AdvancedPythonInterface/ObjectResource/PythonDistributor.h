#ifndef PYDISTRIBUTOR_H
#define PYDISTRIBUTOR_H

#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>
#include <string>
#include <unordered_map>

class ApyiImportObject;
class ApyiPy_Function;
class ApyiDict;

class ApyiDistributor : public UErSingleton<ApyiDistributor>{
public:
    ApyiPy_Function* RequestFunction(const char*);
    ApyiDict* RequestDict(const char*);
    ApyiImportObject* RequestModule(const char*);
    void DistributeFunction(ApyiPy_Function*);
    void DistributeDict(ApyiDict*);
    void DistributeModule(ApyiImportObject*);
    void ReserveShared(ApyiPy_Function*);
    ApyiPy_Function* GetSharedFunction(const char*);

private:
    std::unordered_map<const char*, ApyiPy_Function*> SharedFunctions;
    std::unordered_map<const char*, ApyiPy_Function*> DistributedFunctions;
    std::unordered_map<const char*, ApyiDict*> DistributedDicts;
    std::unordered_map<const char*, ApyiImportObject*> DistributedImports;
};

#endif /* PYDISTRIBUTOR_H */
