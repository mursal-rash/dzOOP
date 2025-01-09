#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

template <typename T>
T findMaxElement(const std::vector<T>& vec) {
    return *std::max_element(vec.begin(), vec.end());
}

template <>
std::pair<int, int> findMaxElement(const std::vector<std::pair<int, int>>& vec) {
    return *std::max_element(vec.begin(), vec.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return (a.first < b.first) || (a.first == b.first && a.second < b.second);
        });
}

int main() {
    std::vector<int> intVec = {1, 3, 2, 5, 4};
    std::cout << "Max int: " << findMaxElement(intVec) << std::endl;

    std::vector<float> floatVec = {1.1f, 3.3f, 2.2f, 5.5f, 4.4f};
    std::cout << "Max float: " << findMaxElement(floatVec) << std::endl;

    std::vector<std::string> stringVec = {"apple", "banana", "cherry"};
    std::cout << "Max string: " << findMaxElement(stringVec) << std::endl;

    std::vector<std::pair<int, int>> pairVec = {{1, 2}, {3, 4}, {2, 5}, {5, 6}, {4, 1}};
    auto maxPair = findMaxElement(pairVec);
    std::cout << "Max pair: (" << maxPair.first << ", " << maxPair.second << ")" << std::endl;

    return 0;
}
