#include <iostream>
#include <string>
#include <algorithm>

void moveSpacesToEnd(std::string& str) 
{
    std::stable_partition(str.begin(), str.end(), [](char c) 
    {
        return c != ' ';
    });
}