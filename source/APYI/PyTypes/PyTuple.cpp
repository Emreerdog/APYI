#include <APYI/PyTypes/PyTuple.h>
#include <APYI/Logging/Logger.h>

ApyiPy_Tuple::ApyiPy_Tuple(PyObject* other)
{
    if(selfPy != NULL)
    {
        SelfClean();
    }
    selfPy = other;
    tupleIndex = GetSize();
}

ApyiPy_Tuple::ApyiPy_Tuple(const ApyiPy_Tuple& rhs)
{
    tupleIndex = rhs.tupleIndex;
    selfPy = rhs.selfPy;
}

ApyiPy_Tuple::ApyiPy_Tuple(size_t givenSize)
{
    tupleIndex = 0;
    selfPy = PyTuple_New(givenSize);
}

void ApyiPy_Tuple::AddItem(ApyiPyPython* givenItem)
{
    if(tupleIndex == GetSize())
    {
        APYI_LOG(ApyiLogging::APYI_OUT_CONSOLE, ApyiLogging::kError, "Tuple object exceeds size");
        return;
    }
    givenItem->IncreaseReference();
    PyTuple_SetItem(selfPy, tupleIndex, givenItem->GetPySelf());
    tupleIndex++;
}

void ApyiPy_Tuple::SetItem(int givenIndex, ApyiPyPython* givenItem)
{
    givenItem->IncreaseReference();
    PyTuple_SetItem(selfPy, givenIndex, givenItem->GetPySelf());
}

PyObject* ApyiPy_Tuple::GetItem(int givenIndex)
{
    return PyTuple_GetItem(selfPy, givenIndex);
}

size_t ApyiPy_Tuple::GetSize()
{
    return PyTuple_Size(selfPy);
}

void ApyiPy_Tuple::Resize(size_t newSize)
{
    
}

ApyiPy_Tuple ApyiPy_Tuple::GetSlice(int low, int high)
{
    PyObject* result = PyTuple_GetSlice(selfPy, low, high);
    if(result == NULL)
    {
        return nullptr;
    }
    return ApyiPy_Tuple(result);
}
