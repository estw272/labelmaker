#include "pch.h"
#include "utility.h"

std::string lm::utility::strings::wstr_to_bytes(std::wstring wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> strconverter;
    return strconverter.to_bytes(wstr);
}
std::wstring lm::utility::strings::bytes_to_wstr(std::string bytes) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> strconverter;
    return strconverter.from_bytes(bytes);
}
