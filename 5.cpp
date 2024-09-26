#include <iostream>
#include <stdio.h>
using std::cout, std::endl;
struct Book
{
char title[100];
int pages;
float  price;
};
void addPrice(struct Book& a, float x)
{
a.price+=x;
}
int main()
{  
struct Book a;
std::cin>>a.title;
std::cin>>a.pages;
std::cin>>a.price;
addPrice(a, 100);
std::cout << a.price << std::endl;
}