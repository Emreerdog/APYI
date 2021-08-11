#ifndef PYTUPLE_H
#define PYTUPLE_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>

#define APYI_TUPLE_RESIZE_CONSTANT 3

class ApyiPy_Tuple : public ApyiPyPython{
public:
    ApyiPy_Tuple(PyObject*);
    ApyiPy_Tuple(const ApyiPy_Tuple&);
    explicit ApyiPy_Tuple(size_t);
    void AddItem(ApyiPyPython*);
    void SetItem(int, ApyiPyPython*);
    PyObject* GetItem(int);
    size_t GetSize();
    ApyiPy_Tuple *GetSlice(int, int);
private:
    size_t tupleSize;
    int tupleIndex;
};

#endif /* PYTUPLE_H */