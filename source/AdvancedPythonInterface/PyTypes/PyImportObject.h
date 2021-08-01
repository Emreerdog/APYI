#ifndef PYIMPORTOBJECT_H
#define PYIMPORTOBJECT_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>

class ApyiPy_Function;
class ApyiDict;

class ApyiImportObject : public ApyiPyPython{
public:
    ApyiImportObject();
    ApyiImportObject(const ApyiImportObject&);
    ~ApyiImportObject();
    ApyiPy_Function GetFunction(const std::string& funcName);
    ApyiDict* GetDict();
    ApyiPyPython* GetVariable(const std::string& varName);
private:
};

#endif /* PYIMPORTOBJECT_H */