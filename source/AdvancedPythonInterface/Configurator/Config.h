#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>
#include <json/json.h>
#include <string>

class ApyiConfig : public UErSingleton<ApyiConfig> {
public:
    void LoadConfigFile(const std::string&);
    void ApplyConfig();
    Json::Value& GetJsonContent();
    void AfterInit();
private:
    Json::Value configContent;
};