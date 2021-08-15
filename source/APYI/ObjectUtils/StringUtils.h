#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <json/json.h>

namespace ApyiStringUtils
{
    void StringToWide(const std::string& given, std::wstring& target);
    std::wstring StringToWide(const std::string& given);
    void WideToString(const std::wstring& given, std::string& target);
    void StringToJson(const std::string& given, Json::Value& target);
    void RemoveExtension(std::string& target);
}

#endif /* STRING_UTILS_H */