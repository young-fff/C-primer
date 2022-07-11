/*
*File : ch02/2.4/const.cpp
*Date : 2022-07-12
*Page : 54
*/

#include <iostream>

extern int a;
const int b = 30;   //const型只能在本文件内用
extern const int c; //在使用时给const变量加extern
int main()
{

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    system("pause");
    return 0;
}