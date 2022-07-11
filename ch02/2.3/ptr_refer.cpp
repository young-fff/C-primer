/*
*File : ch02/2.3/ptr_refer.cpp
*Date : 2022-07-11
*Page : 52
*/

#include<iostream>

int main()
{
    int ival = 42;
    int *p = nullptr;
    int *&r = p;
    std::cout << ival << std::endl;
    std::cout << &ival << std::endl;
    std::cout << p << std::endl;
    std::cout << &p << std::endl;
    std::cout << r << std::endl;
    std::cout << &r << std::endl;

    r = &ival;

    std::cout<< "-------------------" << std::endl;
    std::cout << ival << std::endl;
    std::cout << &ival << std::endl;
    std::cout << p << std::endl;
    std::cout << &p << std::endl;
    std::cout << r << std::endl;
    std::cout << &r << std::endl;



    system("pause");
    return 0;
}