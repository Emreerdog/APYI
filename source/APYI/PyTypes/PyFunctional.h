#ifndef PYFUNCTIONAL_H
#define PYFUNCTIONAL_H

#include <APYI/PyTypes/PyPython.h>
#include <APYI/PyTypes/PyDict.h>
#include <APYI/PyTypes/PyTuple.h>
#include <stdint.h>

class ApyiPy_Function : public ApyiPyPython{
public:
    ApyiPy_Function(PyObject* other);
    ApyiPy_Function(const ApyiPy_Function& other);
    ~ApyiPy_Function();
    //PyObject* operator()();
    //PyObject* operator()(ApyiPyPython*);

    //PyObject* Call();
    //PyObject* Call(ApyiPyPython* arg, ApyiPy_Dict* kwargs = nullptr);
    template<typename Type, typename... Args>
    PyObject* Call(Type& var1, Args&... rest)
    {
        static uint8_t internalCount = 0;
        static uint8_t nArgs = 0;
        // Doing this because template says it can not be converted i don't know the reason.
        if(!givenArguments)
        {
            nArgs = sizeof...(Args);
            if(nArgs == 1) // One argument given
            {
                PyObject* temporaryArgument = var1.GetPySelf();
                return PyObject_CallOneArg(selfPy, temporaryArgument);
            }
            else{ // Multiple arguments
                givenArguments = new ApyiPy_Tuple(nArgs + 1);
            }
        }
        givenArguments->AddItem(&var1);
        Call(rest...);
        internalCount++;
        if(internalCount <= nArgs)
        {
            internalCount = 0; 
            return PyObject_CallObject(selfPy, givenArguments->GetPySelf());
        }
        else // This will never happen wrote this to avoid warnings
        {
            return nullptr;
        }
    }
    PyObject* Call();
    void SetFunctionDict(ApyiPy_Dict* newDict);
    ApyiPy_Dict* GetFunctionDict();
    void AddGlobal(const char* key, ApyiPyPython* targetGlobal);
    // a
private:
    ApyiPy_Dict *FunctionGlobals;
    ApyiPy_Tuple *givenArguments;
};

#endif /* PYFUNCTIONAL_H */