#include <APYI/ObjectUtils/Numbers.h>
#include <APYI/PyTypes/PyString.h>
#include <string>

PyObject* ApyiNumberUtils::FloatFromDecimal(const int& other)
{
    std::string tempBoy = std::to_string(other);
    ApyiPy_String tempPString = tempBoy;
    return PyFloat_FromString(tempPString.GetPySelf());
}

PyObject* ApyiNumberUtils::FloatFromDecimal(const long& other)
{
    std::string tempBoy = std::to_string(other);
    ApyiPy_String tempPString = tempBoy;
    return PyFloat_FromString(tempPString.GetPySelf());
}
