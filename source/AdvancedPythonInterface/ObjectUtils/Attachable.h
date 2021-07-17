#ifndef APYI_ATTACHABLE_H
#define APYI_ATTACHABLE_H

#include <vector>

class UAttachableObject {
public:
	UAttachableObject(bool isMultiple);
	UAttachableObject();
protected:
	bool bIsMultiple;
	void* PresentObject;
	std::vector<void*> AttachedObjects;
};

#endif /* APYI_ATTACHABLE_H */