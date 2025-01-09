#include <iostream>
#include <vector>
#include <array>
#include <string>

template <typename Container>
auto separateOddEven(const Container& container) {
    using ValueType = typename Container::value_type;
    std::vector<std::pair<ValueType, ValueType>> result;

    auto it = container.begin();
    while (it != container.end()) {
        ValueType first = *it++;
        ValueType second = (it != container.end()) ? *it++ : ValueType{};
        result.emplace_back(first, second);
    }

    return result;
}

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    auto resultVec = separateOddEven(vec);
    for (const auto& pair : resultVec) {
        std::cout << "{" << pair.first << ", " << pair.second << "}";
    }
    std::cout << std::endl;

    std::array<std::string, 4> arr = {"cat", "dog", "mouse", "lion"};
    auto resultArr = separateOddEven(arr);
    for (const auto& pair : resultArr) {
        std::cout << "{" << pair.first << ", " << pair.second << "}";
    }
    std::cout << std::endl;

    std::string str = "Hello";
    auto resultStr = separateOddEven(str);
    for (const auto& pair : resultStr) {
        std::cout << "{'" << pair.first << "', '" << pair.second << "'}";
    }

    return 0;
}
