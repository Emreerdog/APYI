#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>
#include <string>
#include <unordered_map>

class ApyiImportObject;
class ApyiPy_Function;
class ApyiDict;

class ApyiDistributor : UErSingleton<ApyiDistributor>{
public:
    ApyiPy_Function* RequestFunction(const std::string&);
    ApyiDict* RequestDict(const std::string&);
    ApyiImportObject* RequestModule(const std::string&);
    void DistributeFunction(ApyiPy_Function*, bool);
    void DistributeDict(ApyiDict*, bool);
    void DistributeModule(ApyiImportObject*, bool);
    
private:
    
    std::unordered_map<const char*, ApyiPy_Function*> DistributedFunctions;
    std::unordered_map<const char*, ApyiDict*> DistributedDicts;
    std::unordered_map<const char*, ApyiImportObject*> DistributedImports;
};
