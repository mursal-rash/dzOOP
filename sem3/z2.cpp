#include <iostream>
#include <string>

std::string operator*(const std::string& str, int n) {
    std::string result;
    for (int i = 0; i < n; ++i) {
        result += str;
    }
    return result;
}

int main() {
    std::string str = "Cat";
    int n = 3;

    std::string result = str * n;

    std::cout << "Результат умножения строки: " << result << std::endl;

    return 0;
}