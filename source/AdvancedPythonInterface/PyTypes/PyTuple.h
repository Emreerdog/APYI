#ifndef PYTUPLE_H
#define PYTUPLE_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>



class ApyiPy_Tuple : public ApyiPyPython{
public:
    ApyiPy_Tuple();
    ApyiPy_Tuple(PyObject*);
    ApyiPy_Tuple(const ApyiPy_Tuple&);
    explicit ApyiPy_Tuple(size_t);
    void AddItem(ApyiPyPython*);
    void SetItem(int, ApyiPyPython*);
    size_t GetSize();
    ApyiPy_Tuple *GetSlice(int, int);
private:
    size_t tupleSize;
    int tupleIndex;
};

#endif /* PYTUPLE_H */