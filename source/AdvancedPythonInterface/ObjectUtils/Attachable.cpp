#include <AdvancedPythonInterface/ObjectUtils/Attachable.h>

UAttachableObject::UAttachableObject(bool isMultiple)
{
	bIsMultiple = isMultiple;
	PresentObject = nullptr;
	AttachedObjects.reserve(15);
}

UAttachableObject::UAttachableObject()
{
	bIsMultiple = false;
	PresentObject = nullptr;
}