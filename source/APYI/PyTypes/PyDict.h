#ifndef PYDICT_H
#define PYDICT_H

#include <APYI/PyTypes/PyPython.h>

class ApyiPy_Dict : public ApyiPyPython{
public:
    ApyiPy_Dict();
    ApyiPy_Dict(PyObject*);
    ApyiPy_Dict(const ApyiPy_Dict&);
    ~ApyiPy_Dict();
    PyObject* operator[](const char*);
    int IsContains(const char*, ApyiPyPython*);
    int SetItem(const char*, ApyiPyPython*);
    int RemoveItem(const char*);
    size_t GetSize();
    PyObject* GetItem(const char*);
    void GetItemAsString(const char*, std::string&);
    PyObject* GetItemList();

private:
    void ClearDict();
};

#endif /* PYDICT_H */