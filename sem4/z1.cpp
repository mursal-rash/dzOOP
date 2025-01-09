#include <iostream>
#include <vector>

void sumEven( std::vector<int>& v)
{
    int s=0;
    for (std::size_t i=0; i < v.size(); ++i)
    {
        if (v[i] % 2 == 0)  
        {
    
             s+= v[i];
        }
    }
    std::cout<<s<<std::endl;
}
int main()
{
std::vector<int> v {10,20,40,35,21};
sumEven(v);
}