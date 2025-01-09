#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    
    std::for_each(numbers.begin(), numbers.end(), [](int &num) { std::cin >> num; });

    auto max_it = std::max_element(numbers.begin(), numbers.end());

    std::sort(numbers.begin(), max_it);
    std::sort(max_it + 1, numbers.end(), std::greater<int>());

    std::for_each(numbers.begin(), numbers.end(), [](int num) { std::cout << num << " "; });
    std::cout << std::endl;

    return 0;
}