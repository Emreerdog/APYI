#ifndef PYDICT_H
#define PYDICT_H

#include <APYI/PyTypes/PyPython.h>

class ApyiPy_Dict : public ApyiPyPython{
public:
    ApyiPy_Dict();
    ApyiPy_Dict(PyObject* other, bool isNew = false);
    ApyiPy_Dict(const ApyiPy_Dict& other);
    ~ApyiPy_Dict();
    // class iterator {
    //     public:

    //     private:

    // };
    PyObject* operator[](const char* key);
    int IsContains(const char* key, ApyiPyPython* value);
    int SetItem(const char* key, ApyiPyPython* value);
    int RemoveItem(const char* key);
    size_t GetSize();
    PyObject* GetItem(const char* key);
    void GetItemAsString(const char* key, std::string& out);
    PyObject* GetItemList();

private:
    void ClearDict();
};

#endif /* PYDICT_H */