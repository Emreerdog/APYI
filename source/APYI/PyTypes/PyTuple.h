#ifndef PYTUPLE_H
#define PYTUPLE_H

#include <APYI/PyTypes/PyPython.h>

#define APYI_TUPLE_RESIZE_CONSTANT 3

class ApyiPy_Tuple : public ApyiPyPython{
public:
    ApyiPy_Tuple(PyObject* other);
    ApyiPy_Tuple(const ApyiPy_Tuple& rhs);
    explicit ApyiPy_Tuple(size_t givenSize);
    void AddItem(ApyiPyPython* givenItem);
    void SetItem(int givenIndex, ApyiPyPython* givenItem);
    PyObject* GetItem(int givenIndex);
    size_t GetSize();
    ApyiPy_Tuple GetSlice(int low, int high);
private:
    int tupleIndex;
};

#endif /* PYTUPLE_H */