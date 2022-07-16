/*
*File : ch06/6.5/constexpr.cpp
*Date : 2022-07-16
*Page : 214
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr int new_sz()
{
    return 42;
}

constexpr size_t scale(size_t cnt)
{
    return new_sz() * cnt;
}

int main()
{
    constexpr int foo = new_sz();
    int arr[scale(2)];
    int i = 2;
    int a2[scale(i)];
    system("pause");
    return 0;
}