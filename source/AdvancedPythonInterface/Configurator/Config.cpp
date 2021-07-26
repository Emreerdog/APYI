#include <AdvancedPythonInterface/ObjectUtils/StringUtils.h>
#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <AdvancedPythonInterface/Configurator/Config.h>
#include <AdvancedPythonInterface/FileSystem/FileSystem.h>
#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
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
    std::wstring defaultPyPath = Py_GetPath();
    modulePath += ApyiStringUtils::StringToWide(configContent["relativeScriptPath"].asCString());
    std::wstring resultPath = defaultPyPath + L":" + modulePath;

    Py_SetPath(resultPath.c_str());
}

void ApyiConfig::AfterInit()
{
    ApyiImportObject* sharedHandlerModule = ApyiImportManager::GetInstance().ImportModule("ctypes", false);
    ApyiPy_Function* sharedHandler = sharedHandlerModule->GetFunction("CDLL");
    for(int i = 0; i < configContent["sharedLibs"].size(); i++)
    {
        ApyiPy_Tuple a();

    }
}

Json::Value& ApyiConfig::GetJsonContent()
{
    return configContent;
}