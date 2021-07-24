#ifndef PYTUPLE_H
#define PYTUPLE_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>

class ApyiPy_Tuple : public ApyiPyPython{
public:
    explicit ApyiPy_Tuple(size_t);
    ApyiPy_Tuple();
    void AddItem(ApyiPyPython*);
    void SetItem(int, ApyiPyPython*);
    size_t GetSize();
    ApyiPy_Tuple *GetSlice(int, int);
private:
    size_t tupleSize;
    int tupleIndex;
};

#endif /* PYTUPLE_H */