#include <AdvancedPythonInterface/PyTypes/PyTuple.h>

ApyiPy_Tuple::ApyiPy_Tuple()
{
    tupleSize = 0;
    tupleIndex = 0;
    selfPy = PyTuple_New(tupleSize + 1);
}

ApyiPy_Tuple::ApyiPy_Tuple(size_t givenSize)
{
    tupleSize = givenSize;
    tupleIndex = 0;
    selfPy = PyTuple_New(givenSize);
}

void ApyiPy_Tuple::AddItem(ApyiPyPython* givenItem)
{
    givenItem->IncreaseReference();
    PyTuple_SetItem(selfPy, tupleIndex, givenItem->GetPySelf());
    tupleIndex++;
}

void ApyiPy_Tuple::SetItem(int givenIndex, ApyiPyPython* givenItem)
{
    givenItem->IncreaseReference();
    PyTuple_SetItem(selfPy, givenIndex, givenItem->GetPySelf());
}

size_t ApyiPy_Tuple::GetSize()
{
    tupleSize = PyTuple_Size(selfPy);
    return tupleSize;
}

ApyiPy_Tuple* ApyiPy_Tuple::GetSlice(int low, int high)
{
    return nullptr;
}
