/*
*File : ch02/2.5/auto.cpp
*Date : 2022-07-12
*Page : 62
*/

#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;

    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;

    const auto f = ci;

    auto &g = ci;
    //auto &h = 42;
    const auto &j = 42;

    auto k = ci, &l = i;
    auto &m = ci, *p = &ci;

    //auto &n = i, *p2 = &ci;
    a = 42;     //auto忽略引用，a是int型
    b = 42;     //auto忽略顶层const，b是int型
    c = 42;     //auto忽略引用和顶层const，c是int型
    //d = 42;     //d是整型指针
    //e = 42;     //e是指向整型常量的指针
    //g = 42;     //g是整型常量引用

    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    system("pause");
    return 0;
    
}