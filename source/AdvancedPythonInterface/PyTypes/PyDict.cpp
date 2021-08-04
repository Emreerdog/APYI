#include <AdvancedPythonInterface/PyTypes/PyDict.h>

ApyiDict::ApyiDict()
{
    selfPy = PyDict_New();
}

ApyiDict::ApyiDict(PyObject* other)
{
    selfPy = other;
}

ApyiDict::ApyiDict(const ApyiDict& other)
{
    selfPy = other.selfPy;
    itemList = other.itemList;
}

ApyiDict::ApyiDict(bool bIsNew)
{
    if(bIsNew)
    {
        selfPy = PyDict_New();
    }
    else
    {
        itemList = nullptr;
    }
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
        Py_CLEAR(itemList);
    }
}

int ApyiDict::IsContains(const std::string& key, ApyiPyPython* value)
{
    PyObject* _key = PyUnicode_FromString(key.c_str());
    int result = PyDict_Contains(selfPy, _key);
    Py_CLEAR(_key);

    return result;
}

int ApyiDict::SetItem(const std::string& key, ApyiPyPython* value)
{
    if(value->GetPySelf() == NULL || value == NULL)
    {
        // TODO
        // Python object is empty
        // Failed to set item
        // Write exception Code...
        return -1;
    }

    return PyDict_SetItemString(selfPy, key.c_str(), value->GetPySelf());
}

int ApyiDict::RemoveItem(const std::string& key)
{
    return PyDict_DelItemString(selfPy, key.c_str());
}

PyObject* ApyiDict::GetItem(const std::string& key)
{
    PyObject* tempItem = PyDict_GetItemString(selfPy, key.c_str());
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

void ApyiDict::GetItemAsString(const std::string& key, std::string& out)
{
    PyObject* itemString = PyDict_GetItemString(selfPy, key.c_str()); // Borrowed
    PyObject* encodedStr = PyUnicode_AsEncodedString(itemString, "UTF-8", "strict");
    out = PyBytes_AS_STRING(encodedStr);
    Py_CLEAR(encodedStr);
}

PyObject* ApyiDict::GetItemList()
{
    if(itemList == NULL)
    {
        itemList = PyDict_Items(selfPy);
    }
    return itemList;
}




