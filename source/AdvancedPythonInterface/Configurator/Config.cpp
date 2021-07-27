#include <AdvancedPythonInterface/ObjectUtils/StringUtils.h>
#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <AdvancedPythonInterface/Configurator/Config.h>
#include <AdvancedPythonInterface/FileSystem/FileSystem.h>
#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyString.h>
#include <AdvancedPythonInterface/PyTypes/PyDict.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
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
    ApyiImportManager& importManager = ApyiImportManager::GetInstance();
    ApyiImportObject* sharedHandlerModule = importManager.ImportModule("ctypes", false);
    ApyiPy_Function* sharedHandler = sharedHandlerModule->GetFunction("CDLL");
    // for(int i = 0; i < configContent["sharedLibs"].size(); i++)
    // {
    //     ApyiPyString tempStr(configContent["sharedLibs"].asCString());
    //     sharedHandler->CallOneArg(&tempStr);
    // }
    std::vector<std::wstring> wScriptFiles = ApyiPathTraits::GetScriptFiles();
    for(auto n : wScriptFiles)
    {
        std::string convertedTypes;
        ApyiStringUtils::WideToString(n, convertedTypes);
        ApyiStringUtils::RemoveExtension(convertedTypes);
        ApyiImportObject* currentModule = importManager.ImportModule(convertedTypes.c_str(), true);
        if(convertedTypes == "myModule")
        {
            ApyiPy_Function* currentFunc = currentModule->GetFunction("shit");
            ApyiDict* funcDict = currentFunc->GetFunctionDict();
            ApyiPyString mString("helloworld");
            funcDict->SetItem("Nude", &mString);
            currentFunc->CallFunc();
        }
    }
}

Json::Value& ApyiConfig::GetJsonContent()
{
    return configContent;
}