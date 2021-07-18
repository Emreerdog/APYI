#ifndef PYDICT_H
#define PYDICT_H

#include <AdvancedPythonInterface/PyTypes/PyPython.h>

class ApyiDict : public ApyiPyPython{
public:
    ApyiDict();
    ApyiDict(bool);
    void ClearDict();
    int IsContains(const std::string&, ApyiPyPython*);
    int SetItem(const std::string&, ApyiPyPython*);
    int RemoveItem(const std::string&);
    PyObject* GetItem(const std::string&);
    void GetItemAsString(const std::string&, std::string&);
    PyObject* GetItemList();

private:
    PyObject* itemList;
};

#endif /* PYDICT_H */