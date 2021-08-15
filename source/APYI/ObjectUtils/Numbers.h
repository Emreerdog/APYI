#ifndef NUMBERS_UTILS_H
#define NUMBERS_UTILS_H

#include <APYI/PyTypes/PyPython.h>

namespace ApyiNumberUtils
{
    PyObject* FloatFromDecimal(const int& other);
    PyObject* FloatFromDecimal(const long& other);
}

#endif /* NUMBERS_UTILS_H */