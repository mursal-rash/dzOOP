#include <iostream>
#include <string_view>
#include <algorithm>
#include <cctype>

bool isIdentifier(std::string_view s) 
{
    if (s.empty() || !std::isalpha(s[0]) && s[0] != '_') 
    {
        return false;
    }

    return std::all_of(s.begin() + 1, s.end(), [](unsigned char c) 
    {
        return std::isalnum(c) || c == '_';
    });
}