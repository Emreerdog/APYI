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

void ApyiDistributor::DistributeFunction(ApyiPy_Function* fPtr, bool bOverwrite=true)
{
    DistributedFunctions[fPtr->GetPyName().c_str()] = fPtr;
}

void ApyiDistributor::DistributeDict(ApyiDict* dPtr, bool bOverwrite=true)
{
    DistributedDicts[dPtr->GetPyName().c_str()] = dPtr;
}

void ApyiDistributor::DistributeModule(ApyiImportObject* iPtr, bool bOverwrite=true)
{
    DistributedImports[iPtr->GetPyName().c_str()] = iPtr;
}