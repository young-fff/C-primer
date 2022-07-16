/*
*File : ch06/6.3/arr_ptr.cpp
*Date : 2022-07-16
*Page : 205
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef int arrT[10];
using arrT = int[10];
arrT * func(int i);

int (*func1(int i))[10];

auto func2(int i) -> int(*)[10];

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i)        //decltype结果是数组，想要指针需要加*号
{
    return (i % 2) ? &odd : &even;
}

string (&func4())[10];

using strR = string[10];
strR &func5();

auto func6() -> string (&)[10];

string str[10];
decltype(str) &func7();

decltype(odd) &arrPtr2(int i)      //decltype结果是数组，想要指针需要加*号
{
    auto &res = (i % 2) ? odd : even;
    return res;
}

int main()
{
    
    system("pause");
    return 0;
}