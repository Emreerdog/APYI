#include <APYI/ObjectUtils/StringUtils.h>
#include <APYI/FileSystem/PathTraits.h>
#include <APYI/Configurator/Config.h>
#include <APYI/FileSystem/FileSystem.h>
#include <APYI/Importer/ImportManager.h>
#include <APYI/PyTypes/PyFunctional.h>
#include <APYI/PyTypes/PyString.h>
#include <APYI/PyTypes/PyDict.h>
#include <APYI/ObjectResource/PythonDistributor.h>
#include <APYI/PyTypes/PyImportObject.h>
#include <iostream>

void ApyiConfig::LoadConfigFile(const std::string& givenConfig)
{
    std::string fOut;
    ApyiFileSystem::ErReadFile(givenConfig.c_str(), fOut);
    ApyiStringUtils::StringToJson(fOut, configContent);
}

void ApyiConfig::ApplyConfig()
{
    // ApyiImportManager& iMng = ApyiImportManager::GetInstance();
    // ApyiImportObject* cLib =  iMng.ImportModule("ctypes", false);
    // ApyiPy_Function* cFuncs = cLib->GetFunction("LoadLibrary");

    std::wstring modulePath;
    ApyiPathTraits::EGetCurrentDir(modulePath);
    std::wstring PydefaultPyPath = Py_GetPath();
    
    modulePath += ApyiStringUtils::StringToWide(configContent["relativeScriptPath"].asCString());
    std::wstring resultPath = PydefaultPyPath + L";" + modulePath;

    Py_SetPath(resultPath.c_str());
}

void ApyiConfig::AfterInit()
{
    // ApyiImportManager& importManager = ApyiImportManager::GetInstance();
    // ApyiDistributor& distributor = ApyiDistributor::GetInstance();
    // ApyiImportObject* sharedHandlerModule = new ApyiImportObject(importManager.ImportModule("ctypes", false));
    // ApyiPy_Function* sharedHandler = new ApyiPy_Function(sharedHandlerModule->GetFunction("CDLL"));
    
    // std::vector<std::wstring> wScriptFiles = ApyiPathTraits::GetScriptFiles();
    // for(auto n : wScriptFiles)
    // {
    //     std::string convertedTypes;
    //     ApyiStringUtils::WideToString(n, convertedTypes);
    //     ApyiStringUtils::RemoveExtension(convertedTypes);
        
    //     ApyiImportObject currentModule = importManager.ImportModule(convertedTypes.c_str(), true);
    //     if(convertedTypes == "myModule")
    //     {
    //         ApyiPy_Function currentFunc = currentModule.GetFunction("shit");
    //         ApyiDict funcDict = currentFunc.GetFunctionDict();
    //         ApyiPyString mString("helloworld");
    //         funcDict.SetItem("Nude", &mString);
    //         currentFunc.CallFunc();
    //     }
    // }
}

Json::Value& ApyiConfig::GetJsonContent()
{
    return configContent;
}