#include <APYI/PyTypes/PyDict.h>
#include <APYI/PyTypes/PyString.h>

ApyiPy_Dict::ApyiPy_Dict()
{
    selfPy = PyDict_New();
}

ApyiPy_Dict::ApyiPy_Dict(PyObject* other, bool isNew)
{
    if(selfPy != NULL)
    {
        ClearDict();
    }

    if(isNew)
    {
        selfPy = PyDict_Copy(other);
    }
    else{
        selfPy = other;
    }
    
}

ApyiPy_Dict::ApyiPy_Dict(const ApyiPy_Dict& other)
{
    if(selfPy != NULL)
    {
        ClearDict();
    }
    selfPy = PyDict_Copy(other.selfPy);
}

ApyiPy_Dict::~ApyiPy_Dict()
{
    ClearDict();
}

PyObject* ApyiPy_Dict::operator[](const char* key)
{
    PyObject* tempItem = PyDict_GetItemString(selfPy, key);
    return tempItem;
}

void ApyiPy_Dict::ClearDict()
{
    if(EPF == ApyiPyFlag::APYI_RELEASE)
    {
        PyDict_Clear(selfPy);
    }
}

int ApyiPy_Dict::IsContains(const char* key, ApyiPyPython* value)
{
    PyObject* _key = PyUnicode_FromString(key);
    int result = PyDict_Contains(selfPy, _key);
    Py_CLEAR(_key);

    return result;
}

int ApyiPy_Dict::SetItem(const char* key, ApyiPyPython* value)
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

int ApyiPy_Dict::RemoveItem(const char* key)
{
    return PyDict_DelItemString(selfPy, key);
}

size_t ApyiPy_Dict::GetSize()
{
    return PyDict_Size(selfPy);
}

PyObject* ApyiPy_Dict::GetItem(const char* key)
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

void ApyiPy_Dict::GetItemAsString(const char* key, std::string& out)
{
    PyObject* itemString = PyDict_GetItemString(selfPy, key); // Borrowed
    
    PyObject* encodedStr = PyUnicode_AsEncodedString(itemString, "UTF-8", "strict");
    out = PyBytes_AS_STRING(encodedStr);
    Py_CLEAR(encodedStr);
}

PyObject* ApyiPy_Dict::GetItemList()
{
    return PyDict_Items(selfPy);
}


