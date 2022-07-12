/*
*File : ch02/2.4/test_constexpr.cpp
*Date : 2022-07-12
*Page : 60
*/

#include <iostream>

int j = 0;

int main()
{
    constexpr int * p1 = &j;
    system("pause");
    return 0;
    
}