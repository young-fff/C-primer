/*
*File : ch02/2.4/constexpr.cpp
*Date : 2022-07-12
*Page : 59
*/

#include <iostream>

constexpr int getsize()
{
    return 50;
}

int main()
{
    //int a = 20;
    //constexpr int b = a;

    //const int c = 30;
    //constexpr int d = c;

    constexpr int e = getsize();
    system("pause");
    return 0;
    
}