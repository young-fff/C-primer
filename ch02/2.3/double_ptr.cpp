/*
*File : ch02/2.3/double_ptr.cpp
*Date : 2022-07-11
*Page : 52
*/

#include<iostream>

int main()
{
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;

    std::cout << ival << std::endl;
    std::cout << &ival << std::endl;
    std::cout << pi << std::endl;
    std::cout << &pi << std::endl;
    std::cout << *pi << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << ppi << std::endl;
    std::cout << &ppi << std::endl;
    std::cout << *ppi << std::endl;
    std::cout << **ppi << std::endl;

    system("pause");
    return 0;
}