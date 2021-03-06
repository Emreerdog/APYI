#ifndef PYIMPORTOBJECT_H
#define PYIMPORTOBJECT_H

#include <APYI/PyTypes/PyPython.h>

class ApyiPy_Function;
class ApyiPy_Dict;

class ApyiImportObject : public ApyiPyPython{
public:
    ApyiImportObject();
    ApyiImportObject(PyObject* other);
    ApyiImportObject(const ApyiImportObject& other);
    ApyiPy_Function *GetFunction(const char* funcName);
    PyObject* GetAttribute(const char* varName);
private:
};

#endif /* PYIMPORTOBJECT_H */