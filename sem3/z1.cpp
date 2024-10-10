#include <iostream>
#include <string>
#include <cctype>

std::string changeFirstLetterCase(const std::string& str) {
    if (str.empty()) {
        return "";
    }

    std::string result = str;

    if (std::isupper(result[0])) {
        result[0] = std::tolower(result[0]);
    } else {
        result[0] = std::toupper(result[0]);
    }

    return result;
}

int main() {
    std::string str1 = "Cat";
    std::string str2 = "dog";
    std::string str3 = "";

    std::cout << changeFirstLetterCase(str1) << std::endl;
    std::cout << changeFirstLetterCase(str2) << std::endl;
    std::cout << changeFirstLetterCase(str3) << std::endl;

    return 0;
}
