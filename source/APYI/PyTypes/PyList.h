#ifndef PYLIST_H
#define PYLIST_H

#include <APYI/PyTypes/PyPython.h>

class ApyiPy_Long;

class ApyiPy_List : public ApyiPyPython{
public:
    ApyiPy_List();
    ApyiPy_List(PyObject* other);
    ApyiPy_List(const ApyiPy_List& other);
    ~ApyiPy_List();
    PyObject* operator[](size_t index);
    void SetItem(size_t index, ApyiPyPython* item);
    size_t GetSize();
    PyObject* GetItem(size_t index);
    ApyiPy_List GetSlice(int low, int high);
    void AddItem(ApyiPyPython* givenItem);
private:
};

#endif /* PYLIST_H */