#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <json/json.h>

namespace ApyiStringUtils
{
    void StringToWide(const std::string&, std::wstring&);
    std::wstring StringToWide(const std::string&);
    void WideToString(const std::wstring&, std::string&);
    void StringToJson(const std::string&, Json::Value&);
    void RemoveExtension(std::string&);

}

#endif /* STRING_UTILS_H */