#include <iostream>
#include <stdio.h>
using std::cout, std::endl;
struct Book
{
    char title[100];
    int pages;
    float  price;
};
bool isExpensive(const Book& a ){
   if (a.price>1000)
    return 1;
    else return 0;

}
int main()
{
    struct Book a;
    std::cin>>a.title;
    std::cin>>a.pages;
    std::cin>>a.price;
    std::cout<<isExpensive(a)<<std::endl;
}