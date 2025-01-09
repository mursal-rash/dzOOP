#include <iostream>
#include <set>

int main() 
{
    int count;
    std::cin >> count;

    std::multiset<int> numbers;
    for (int i = 0; i < count; ++i) 
    {
        int value;
        std::cin >> value;
        numbers.insert(value);
    }

    for (const auto& value : numbers) 
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
