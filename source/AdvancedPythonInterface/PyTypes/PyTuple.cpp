#include <AdvancedPythonInterface/PyTypes/PyTuple.h>
#include <AdvancedPythonInterface/Logging/Logger.h>

ApyiPy_Tuple::ApyiPy_Tuple(PyObject* other)
{
    if(!PyTuple_Check(other))
    {
        APYI_LOG(ApyiLogging::APYI_OUT_CONSOLE, ApyiLogging::kError, "Given object is not TUPLE type");
        selfPy = nullptr;
        tupleSize = 0;
        tupleIndex = 0;
    }
    selfPy = other;
    tupleSize = GetSize();
    tupleIndex = tupleSize;
}

ApyiPy_Tuple::ApyiPy_Tuple(const ApyiPy_Tuple& rhs)
{
    tupleSize = rhs.tupleSize;
    tupleIndex = rhs.tupleIndex;
    selfPy = rhs.selfPy;
}

ApyiPy_Tuple::ApyiPy_Tuple(size_t givenSize)
{
    tupleSize = givenSize;
    tupleIndex = 0;
    selfPy = PyTuple_New(tupleSize);
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
    tupleSize = PyTuple_Size(selfPy);
    return tupleSize;
}

ApyiPy_Tuple* ApyiPy_Tuple::GetSlice(int low, int high)
{
    return nullptr;
}
