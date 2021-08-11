#include <APYI/ObjectResource/ObjectResource.h>

ApyiResourceManager::ApyiResourceManager()
{
    cCursor = 0;
    itemRemoved = 0;
    defaultCapacity = 5000;
    reservedObjects.reserve(defaultCapacity);
}

uint32_t ApyiResourceManager::ReserveObject(void* target)
{
    uint32_t temp_cursor;
    if (itemRemoved != 0)
    {
        temp_cursor = itemRemoved;
        reservedObjects[temp_cursor] = target;
        itemRemoved = 0;
    }
    else
    {
        temp_cursor = cCursor;
        if (temp_cursor == reservedObjects.size())
        {
            IncreaseCapacity();
        }
        reservedObjects[temp_cursor] = target;
        (++cCursor);
    }

    return temp_cursor;
}

void* ApyiResourceManager::GetReservedObject(uint32_t objId)
{
    return reservedObjects[objId];
}

void ApyiResourceManager::UnRegisterObject(uint32_t objId)
{
    itemRemoved = objId;
    reservedObjects[itemRemoved] = nullptr;
}

void ApyiResourceManager::IncreaseCapacity()
{
    defaultCapacity *= 2;
    reservedObjects.resize(defaultCapacity);
}
