#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>
#include <json/json.h>
#include <string>

class ApyiInitConfig : public UErSingleton<ApyiInitConfig> {
public:
    void LoadConfigFile(const std::string&);
    void ApplyConfig();
    Json::Value& GetJsonContent();

private:
    Json::Value configContent;
};