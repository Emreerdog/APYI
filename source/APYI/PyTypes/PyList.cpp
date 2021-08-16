#include <APYI/PyTypes/PyList.h>
#include <APYI/PyTypes/PyLong.h>

ApyiPy_List::ApyiPy_List()
{

}

ApyiPy_List::ApyiPy_List(PyObject* other)
{
    if(selfPy != NULL)
    {
        SelfClean();
    }
    selfPy = other;
}

ApyiPy_List::ApyiPy_List(const ApyiPy_List& other)
{

}

ApyiPy_List::~ApyiPy_List()
{

}

PyObject* ApyiPy_List::operator[](size_t index)
{
    return PyList_GetItem(selfPy, index);
}

void ApyiPy_List::SetItem(size_t index, ApyiPyPython* item)
{
    PyList_SET_ITEM(selfPy, index, item->GetPySelf());
}

size_t ApyiPy_List::GetSize()
{
    return PyList_GET_SIZE(selfPy);
}

PyObject* ApyiPy_List::GetItem(size_t index)
{
    return PyList_GET_ITEM(selfPy, index);
}

ApyiPy_List ApyiPy_List::GetSlice(int low, int high)
{
    PyObject* result = PyList_GetSlice(selfPy, low, high);
    return ApyiPy_List(result);
}

void ApyiPy_List::AddItem(ApyiPyPython* givenItem)
{
    PyList_Append(selfPy, givenItem->GetPySelf());
}

