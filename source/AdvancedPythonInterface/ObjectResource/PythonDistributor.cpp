#include <AdvancedPythonInterface/ObjectResource/PythonDistributor.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>

ApyiPy_Function* ApyiDistributor::RequestFunction(const char* fName)
{
    auto resultant = DistributedFunctions.find(fName);
    if(resultant != DistributedFunctions.end())
    {
        return resultant->second;
    }
    
    return nullptr; // Not found
}

ApyiDict* ApyiDistributor::RequestDict(const char* dName)
{
    auto resultant = DistributedDicts.find(dName);
    if(resultant != DistributedDicts.end())
    {
        return resultant->second;
    }

    return nullptr; // Not found
}

ApyiImportObject* ApyiDistributor::RequestModule(const char* mName)
{
    auto resultant = DistributedImports.find(mName);
    if(resultant != DistributedImports.end())
    {
        return resultant->second;
    }

    return nullptr; // Not found
}

void ApyiDistributor::DistributeFunction(ApyiPy_Function* fPtr)
{
    DistributedFunctions[fPtr->GetPyName().c_str()] = fPtr;
}

void ApyiDistributor::DistributeDict(ApyiDict* dPtr)
{
    DistributedDicts[dPtr->GetPyName().c_str()] = dPtr;
}

void ApyiDistributor::DistributeModule(ApyiImportObject* iPtr)
{
    DistributedImports[iPtr->GetPyName().c_str()] = iPtr;
}

void ApyiDistributor::ReserveShared(ApyiPy_Function* sName)
{
    SharedFunctions[sName->GetPyName().c_str()] = sName;
}

ApyiPy_Function* ApyiDistributor::GetSharedFunction(const char* target)
{
    auto resultant = SharedFunctions.find(target);
    if(resultant != SharedFunctions.end())
    {
        return resultant->second;
    }

    return nullptr; // Not found
}