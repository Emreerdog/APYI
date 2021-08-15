#include <APYI/PyTypes/PyDict.h>
#include <APYI/PyTypes/PyString.h>

ApyiDict::ApyiDict()
{
    selfPy = PyDict_New();
}

ApyiDict::ApyiDict(PyObject* other)
{
    if(selfPy != NULL)
    {
        ClearDict();
    }
    selfPy = other;
}

ApyiDict::ApyiDict(const ApyiDict& other)
{
    if(selfPy != NULL)
    {
        ClearDict();
    }
    selfPy = PyDict_Copy(other.selfPy);
}

ApyiDict::~ApyiDict()
{
    ClearDict();
}

void ApyiDict::ClearDict()
{
    if(EPF == ApyiPyFlag::APYI_RELEASE)
    {
        PyDict_Clear(selfPy);
    }
}

int ApyiDict::IsContains(const char* key, ApyiPyPython* value)
{
    PyObject* _key = PyUnicode_FromString(key);
    int result = PyDict_Contains(selfPy, _key);
    Py_CLEAR(_key);

    return result;
}

int ApyiDict::SetItem(const char* key, ApyiPyPython* value)
{
    if(value->GetPySelf() == NULL || value == NULL)
    {
        // TODO
        // Python object is empty
        // Failed to set item
        // Write exception Code...
        return -1;
    }

    return PyDict_SetItemString(selfPy, key, value->GetPySelf());
}

int ApyiDict::RemoveItem(const char* key)
{
    return PyDict_DelItemString(selfPy, key);
}

PyObject* ApyiDict::GetItem(const char* key)
{
    PyObject* tempItem = PyDict_GetItemString(selfPy, key);
    if(tempItem == NULL)
    {
        // TODO
        // Given item doesn't exist on dict
        //
        // Write exception Code...
        return nullptr;
    }
    
    return tempItem;
}

void ApyiDict::GetItemAsString(const char* key, std::string& out)
{
    PyObject* itemString = PyDict_GetItemString(selfPy, key); // Borrowed
    
    PyObject* encodedStr = PyUnicode_AsEncodedString(itemString, "UTF-8", "strict");
    out = PyBytes_AS_STRING(encodedStr);
    Py_CLEAR(encodedStr);
}

PyObject* ApyiDict::GetItemList()
{
    return PyDict_Items(selfPy);
}


