#ifndef APYI_IMPORTMANAGER_H
#define APYI_IMPORTMANAGER_H

#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>
#include <string>

class ApyiImportObject;

class ApyiImportManager : public UErSingleton<ApyiImportManager>{
public:
    ApyiImportManager();
    ApyiImportObject* ImportModule(const char*, bool);
private:
};

#endif /* APYI_IMPORTMANAGER_H */