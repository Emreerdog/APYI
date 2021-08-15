#include <APYI/ObjectUtils/StringUtils.h>
#include <codecvt>
#include <locale>

using convert_t = std::codecvt_utf8<wchar_t>;
std::wstring_convert<convert_t, wchar_t> sConv;

void ApyiStringUtils::StringToWide(const std::string& given, std::wstring& target)
{
    target = sConv.from_bytes(given);
}

std::wstring ApyiStringUtils::StringToWide(const std::string& given)
{
    return sConv.from_bytes(given);
}

void ApyiStringUtils::WideToString(const std::wstring& given, std::string& target)
{
    target = sConv.to_bytes(given);
}

void ApyiStringUtils::StringToJson(const std::string& given, Json::Value& target)
{
    std::stringstream sToJson(given);
    sToJson >> target;
}

void ApyiStringUtils::RemoveExtension(std::string& target){
    size_t extensionPart = target.find_last_of(".");
    if(extensionPart == std::string::npos)
    {
        // Do nothing
        return;
    }
    target = target.substr(0, extensionPart);
}