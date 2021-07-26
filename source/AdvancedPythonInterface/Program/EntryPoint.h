#include <AdvancedPythonInterface/ObjectUtils/Singleton.h>

class ApyiEntryPoint : public UErSingleton<ApyiEntryPoint>{
public:
    ApyiEntryPoint();
    ~ApyiEntryPoint();
    void Initialize();
    void Finalize();
private:
};