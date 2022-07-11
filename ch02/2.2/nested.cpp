/*
*File : ch02/2.2/nested.cpp
*Date : 2022-07-11
*Page : 44
*/

#include<iostream>

int reused = 42;

int main()
{
    int unique = 10;
    std::cout << reused << std::endl;

    int reused = 20;
    std::cout << reused << std::endl;
    std::cout << ::reused << std::endl; //::表示全局作用域
    system("pause");
    return 0;
}