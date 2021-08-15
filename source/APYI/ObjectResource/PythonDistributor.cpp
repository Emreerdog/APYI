#include <APYI/ObjectResource/PythonDistributor.h>
#include <APYI/PyTypes/PyFunctional.h>
#include <APYI/PyTypes/PyImportObject.h>
#include <APYI/PyTypes/PyDict.h>

ApyiPy_Function* ApyiDistributor::RequestFunction(const char* fName)
{
    auto resultant = DistributedFunctions.find(fName);
    if(resultant != DistributedFunctions.end())
    {
        return resultant->second;
    }
    
    return nullptr; // Not found
}

ApyiPy_Dict* ApyiDistributor::RequestDict(const char* dName)
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

void ApyiDistributor::DistributeDict(ApyiPy_Dict* dPtr)
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