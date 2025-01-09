#include <iostream>
#include <list>

void killOrder(int totalWarriors, int step) 
{
    std::list<int> warriors;
    for (int i = 1; i <= totalWarriors; ++i) 
    {
        warriors.push_back(i);
    }

    auto it = warriors.begin();

    while (warriors.size() > 1) 
    {
        for (int count = 1; count < step; ++count) 
        {
            ++it;
            if (it == warriors.end()) 
            {
                it = warriors.begin();
            }
        }
        std::cout << *it << " ";
        it = warriors.erase(it);
        if (it == warriors.end()) 
        {
            it = warriors.begin();
        }
    }

    std::cout << "\nSurvivor: " << warriors.front() << std::endl;
}

int main() 
{
    int n, m;
    std::cin >> n >> m; // Используйте std::cin вместо просто cin
    killOrder(n, m);
    return 0;
}
