#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

void reverseStringsAndVector(std::vector<std::string>& strVec) 
{
    for (auto& str : strVec) 
    {
        std::reverse(str.begin(), str.end());
    }
    std::reverse(strVec.begin(), strVec.end());
}

int main() 
{
    std::vector<std::string> inputStrings((std::istream_iterator<std::string>(std::cin)),
                                          std::istream_iterator<std::string>());

    reverseStringsAndVector(inputStrings);

    for (const auto& str : inputStrings) 
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
