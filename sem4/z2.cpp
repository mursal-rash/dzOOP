#include <iostream>
#include <vector>

void lastDigits( std::vector<int>& v)
{
    int s=0;
    for (std::size_t i=0; i < v.size(); ++i)
    {
        v[i]=v[i] % 10;
        
    }
}
int main()
{
std::vector<int> v {10,20,40,35,21};
lastDigits(v);
}