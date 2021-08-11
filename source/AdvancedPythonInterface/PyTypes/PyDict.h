#ifndef PYDICT_H
#define PYDICT_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>

class ApyiDict : public ApyiPyPython{
public:
    ApyiDict();
    ApyiDict(PyObject*);
    ApyiDict(const ApyiDict&);
    ApyiDict(bool);
    ~ApyiDict();
    int IsContains(const char*, ApyiPyPython*);
    int SetItem(const char*, ApyiPyPython*);
    int RemoveItem(const char*);
    PyObject* GetItem(const char*);
    void GetItemAsString(const char*, std::string&);
    PyObject* GetItemList();

private:
    void ClearDict();
    PyObject* itemList;
};

#endif /* PYDICT_H */