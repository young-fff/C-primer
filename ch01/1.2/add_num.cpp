/*
*File : ch01/1.2/add_num.cpp
*Date : 2022-07-10
*Page : 5
*/

#include<iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1=0, v2=0;
    std::cin >> v1 >> v2;
    std::cout<< " The sum of " << v1 << " and " << v2 
            << " is " << v1 + v2 << std::endl;
    return 0;
}