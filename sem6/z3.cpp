#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isUpperCase(const std::string& str) 
{
    return std::all_of(str.begin(), str.end(), [](unsigned char c) { return std::isupper(c) || !std::isalpha(c); });
}