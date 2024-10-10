#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

int sumFromString(const std::string& str) {
    if (str.empty() || str[0] != '[' || str[str.size() - 1] != ']') {
        throw std::invalid_argument("Некорректная строка");
    }

    std::string numbers = str.substr(1, str.size() - 2); // Убираем квадратные скобки
    std::stringstream ss(numbers);
    std::string item;
    int sum = 0;

    while (std::getline(ss, item, ',')) {
        try {
            sum += std::stoi(item); // Пробуем преобразовать строку в число
        } catch (const std::invalid_argument&) {
            // Если не удалось преобразовать, игнорируем элемент
        }
    }

    return sum;
}

int main() {
    try {
        std::cout << "Сумма: " << sumFromString("[10, 20, 30, 40, 50]") << std::endl; // 150
        std::cout << "Сумма: " << sumFromString("[20, %, 15, 16, 23, 42)") << std::endl; // Исключение
        std::cout << "Сумма: " << sumFromString("[]") << std::endl; // 0
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}