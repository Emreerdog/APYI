#include <AdvancedPythonInterface/ObjectUtils/NonCopyable.h>

template <class Type> class UErSingleton : public UErNonCopyable {
public:
    static Type& GetInstance() {
        static Type instance;
        return instance;
    }
};