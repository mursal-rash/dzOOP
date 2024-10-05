#include <iostream>
int  cubeR(int& n)
{
        return n*n*n;
}
int main()
{
    int x;
   std::cin>> x;
   int cub = cubeR(x);
   std::cout << cub << std::endl;

}