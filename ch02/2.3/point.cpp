/*
*File : ch02/2.3/point.cpp
*Date : 2022-07-11
*Page : 47
*/

#include<iostream>

int main()
{
    int ival = 42;
    int *p = &ival;

    std::cout << ival << std::endl;
    std::cout << &ival << std::endl;
    std::cout << p << std::endl;
    std::cout << &p << std::endl;
    std::cout << *p << std::endl;

    *p = 21;
    std::cout << ival << std::endl;
    std::cout << &ival << std::endl;
    std::cout << p << std::endl;
    std::cout << &p << std::endl;
    std::cout << *p << std::endl;

    system("pause");
    return 0;
}