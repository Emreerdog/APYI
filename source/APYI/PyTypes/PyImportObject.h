#ifndef PYIMPORTOBJECT_H
#define PYIMPORTOBJECT_H

#include <APYI/PyTypes/PyPython.h>

class ApyiPy_Function;
class ApyiDict;

class ApyiImportObject : public ApyiPyPython{
public:
    ApyiImportObject();
    ApyiImportObject(const ApyiImportObject& other);
    ~ApyiImportObject();
    ApyiPy_Function *GetFunction(const char* funcName);
    PyObject* GetAttribute(const char* varName);
private:
};

#endif /* PYIMPORTOBJECT_H */