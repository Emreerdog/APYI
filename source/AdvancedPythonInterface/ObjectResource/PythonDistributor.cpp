#include <AdvancedPythonInterface/ObjectResource/PythonDistributor.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>

ApyiPy_Function* ApyiDistributor::RequestFunction(const std::string& fName)
{
    auto resultant = DistributedFunctions.find(fName.c_str());
    if(resultant != DistributedFunctions.end())
    {
        return resultant->second;
    }
    
    return nullptr; // Not found
}

ApyiDict* ApyiDistributor::RequestDict(const std::string& dName)
{
    auto resultant = DistributedDicts.find(dName.c_str());
    if(resultant != DistributedDicts.end())
    {
        return resultant->second;
    }

    return nullptr; // Not found
}

ApyiImportObject* ApyiDistributor::RequestModule(const std::string& mName)
{
    auto resultant = DistributedImports.find(mName.c_str());
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

ApyiPy_Function* ApyiDistributor::GetSharedFunction(const std::string& target)
{
    auto resultant = SharedFunctions.find(target.c_str());
    if(resultant != SharedFunctions.end())
    {
        return resultant->second;
    }

    return nullptr; // Not found
}