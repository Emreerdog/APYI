#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>
#include <string>

class ApyiImportObject;
class ApyiPy_Function;
class ApyiDict;

class ApyiDistributor : UErSingleton<ApyiDistributor>{
public:
    ApyiPy_Function* RequestFunction(const std::string&);
    ApyiDict* RequestDict(const std::string&);
    ApyiImportObject* RequestModule(const std::string&);
    void DistributeFunction(ApyiPy_Function*);
    void DistributeDict(ApyiDict*);
    void DistributeModule(ApyiImportObject*);
    
private:
};
