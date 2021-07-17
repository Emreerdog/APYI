#ifndef APYI_IMPORTMANAGER_H
#define APYI_IMPORTMANAGER_H

#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>
#include <AdvancedPythonInterface/PyTypes/PyPython.h>

class ApyiImportObject;

class ApyiImportManager : public UErSingleton<ApyiImportManager>, public ApyiPyPython{
public:
    ApyiImportManager();
    ApyiImportObject* ImportModule(const std::string& moduleName);
private:
};

#endif /* APYI_IMPORTMANAGER_H */