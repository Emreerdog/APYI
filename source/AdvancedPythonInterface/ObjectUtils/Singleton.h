#ifndef APYI_SINGLETON_H
#define APYI_SINGLETON_H

#include <AdvancedPythonInterface/ObjectUtils/NonCopyable.h>

template <class Type> class UErSingleton : public UErNonCopyable {
public:
    static Type& GetInstance() {
        static Type instance;
        return instance;
    }
};

#endif /* APYI_SINGLETON_H */