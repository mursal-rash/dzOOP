#include <iostream>
using std::cout, std::endl;
namespace myspace {
    void priNTimes(const char*str, int n )
    {
       for (int i = 1; i <= n; ++i)
        
        {
        std::cout << str <<std::endl;
        
        }  
    }
}

int main()
{
  myspace::priNTimes("Hello, world", 10);
}