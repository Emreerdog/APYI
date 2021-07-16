#include <AdvancedPythonInterface/PyTypes/PyPython.h>
#include <vector>

class ApyiPy_Function : public ApyiPyPython{
public:
    explicit ApyiPy_Function(const std::string& callFrom, const std::string& fName);
    PyObject* CallFunc();
    std::vector<std::string> GetImportList();
    void BindFunc(const std::string& name);

private:
    std::vector<std::string> Import_Vec;
    std::string presentCaller;
};