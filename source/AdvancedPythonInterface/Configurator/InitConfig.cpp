#include <AdvancedPythonInterface/ObjectUtils/StringUtils.h>
#include <AdvancedPythonInterface/FileSystem/PathTraits.h>
#include <AdvancedPythonInterface/Configurator/InitConfig.h>
#include <AdvancedPythonInterface/FileSystem/FileSystem.h>
#include <AdvancedPythonInterface/Importer/ImportManager.h>
#include <AdvancedPythonInterface/PyTypes/PyFunctional.h>
#include <AdvancedPythonInterface/PyTypes/PyImportObject.h>
#include <iostream>

void ApyiInitConfig::LoadConfigFile(const std::string& givenConfig)
{
    std::string fOut;
    ApyiFileSystem::ErReadFile(givenConfig.c_str(), fOut);
    ApyiStringUtils::StringToJson(fOut, configContent);
}

void ApyiInitConfig::ApplyConfig()
{
    // ApyiImportManager& iMng = ApyiImportManager::GetInstance();
    // ApyiImportObject* cLib =  iMng.ImportModule("ctypes", false);
    // ApyiPy_Function* cFuncs = cLib->GetFunction("LoadLibrary");

    std::wstring modulePath;
    ApyiPathTraits::EGetCurrentDir(modulePath);
    std::wstring defaultPyPath = Py_GetPath();
    std::wstring resultPath = defaultPyPath + L":" + modulePath;
    std::cout << configContent["relativeScriptPath"] << "sikem" << std::endl;
    Py_SetPath(resultPath.c_str());
}

Json::Value& ApyiInitConfig::GetJsonContent()
{
    return configContent;
}