#ifndef APYI_OBJECTRESOURCES_H
#define APYI_OBJECTRESOURCES_H

#include <APYI/ObjectUtils/Singleton.h>

#include <vector>
#include <thread>
#include <atomic>
#include <stdint.h>

class ApyiResourceManager : public UErSingleton<ApyiResourceManager>
{
public:
    ApyiResourceManager();
    uint32_t ReserveObject(void*);
    void* GetReservedObject(uint32_t);
    void UnRegisterObject(uint32_t);

private:
    void IncreaseCapacity();
    std::vector<void*> reservedObjects;
    std::atomic<uint32_t> cCursor;
    std::atomic<uint32_t> itemRemoved;
    uint32_t defaultCapacity;
};

#endif /* APYI_OBJECTRESOURCES_H */