/*
*File : ch02/2.3/reference.cpp
*Date : 2022-07-11
*Page : 46
*/

#include<iostream>

int main()
{
    int i = 1024, i2 = 2048;
    int &r = i, r2 = i2;
    int i3 = 1024, &r3 = i3;
    std::cout << r << std::endl;

    system("pause");
    return 0;
}