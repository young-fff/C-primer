/*
*File : ch02/2.5/decltype.cpp
*Date : 2022-07-12
*Page : 63
*/

#include <iostream>

int main()
{
    const int ci = 0, &cj = ci;
    decltype (ci) x = 0;
    decltype (cj) y = x;
    //decltype (cj) z; //z是一个引用，必须初始化

    //decltype的结果可以是引用类型
    int i = 42, *p = &i, &r = i;
    //decltype (r) b;   //此处b是一个整型引用
    decltype (r + 0) b;   //此处b是一个整型，因为r + 0的计算结果是一个整型
    //decltype (*P) c;  //c是整型引用,必须初始化
    
    //decltype的表达式如果是加上了括号的变量，结果将是引用
    //decltype ((i)) d;   //d是整型引用
    decltype (i) e;     //e是一个(未初始化的) int
    system("pause");
    return 0;
    
}