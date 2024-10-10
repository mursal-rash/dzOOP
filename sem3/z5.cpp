#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <algorithm>

int sumFromString(const std::string& input) {
    if (input.empty() || input.front() != '[' || input.back() != ']') {
        throw std::invalid_argument("Некорректный формат строки");
    }

    std::string numbers = input.substr(1, input.size() - 2);
    std::stringstream ss(numbers);
    std::string number;
    int sum = 0;

    while (std::getline(ss, number, ',')) {
        number.erase(remove_if(number.begin(), number.end(), isspace), number.end());
        if (!number.empty()) {
            try {
                sum += std::stoi(number);
            } catch (const std::invalid_argument&) {
                throw std::invalid_argument("Некорректное число: " + number);
            } catch (const std::out_of_range&) {
                throw std::invalid_argument("Число вне допустимого диапазона: " + number);
            }
        }
    }

    return sum;
}

int main() {
    try {
        std::string input1 = "[1, 2, 3, 4]";
        std::string input2 = "[10, -5, 0]";
        std::string input3 = "[]";
        std::string input4 = "[1, a, 3]";

        std::cout << "Сумма из строки 1: " << sumFromString(input1) << std::endl;
        std::cout << "Сумма из строки 2: " << sumFromString(input2) << std::endl;
        std::cout << "Сумма из строки 3: " << sumFromString(input3) << std::endl;
        std::cout << "Сумма из строки 4: " << sumFromString(input4) << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
