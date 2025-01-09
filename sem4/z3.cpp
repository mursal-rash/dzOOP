#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> factorization(int n) {
    std::vector<std::pair<int, int>> factors;

    if (n == 1) {
        factors.emplace_back(1, 1);
        return factors;
    }

    int count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    if (count > 0) {
        factors.emplace_back(2, count);
    }

    for (int i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            factors.emplace_back(i, count);
        }
    }

    if (n > 2) {
        factors.emplace_back(n, 1);
    }

    return factors;
}

int main() {
    std::vector<std::pair<int, int>> result;

    result = factorization(60);
    std::cout << "Факторизация 60: ";
    for (const auto& factor : result) {
        std::cout << "{" << factor.first << ", " << factor.second << "} ";
    }
    std::cout << std::endl;

    result = factorization(626215995);
    std::cout << "Факторизация 626215995: ";
    for (const auto& factor : result) {
        std::cout << "{" << factor.first << ", " << factor.second << "} ";
    }
    std::cout << std::endl;

    result = factorization(107);
    std::cout << "Факторизация 107: ";
    for (const auto& factor : result) {
        std::cout << "{" << factor.first << ", " << factor.second << "} ";
    }
    std::cout << std::endl;

    result = factorization(1);
    std::cout << "Факторизация 1: ";
    for (const auto& factor : result) {
        std::cout << "{" << factor.first << ", " << factor.second << "} ";
    }
    std::cout << std::endl;

    return 0;
}