#include <iostream>
#include <set>
#include <vector>

int main() 
{
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (auto& num : numbers) 
    {
        std::cin >> num;
    }

    std::set<int> unique_numbers(numbers.begin(), numbers.end());

    for (const auto& num : unique_numbers) 
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}
