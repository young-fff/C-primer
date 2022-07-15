/*
*File : ch06/6.1/fact.cpp
*Date : 2022-07-15
*Page : 182
*/

#include <iostream>
#include <vector>
#include <string>
#include "Chapter6.h"
using namespace std;

size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}
size_t count_calls2()
{
    static size_t ctr = 0;
    return ctr++;
}
size_t count_calls3(int val)
{
    static size_t ctr = 0;
    int num = val * 2;
    return ++ctr * num;
}
int main()
{
    for (size_t i = 0; i != 10; ++i)
        cout << count_calls2() << "   " << count_calls3(2) << endl;
    system("pause");
    return 0;
}