/*
*File : ch04/4.9/size_of.cpp
*Date : 2022-07-14
*Page : 140
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int x[10]; 
    int *p = x;
    int *q[10] = {x};
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;     //p是指向int类型的指针
    cout << sizeof(q) / sizeof(*q) << endl;     //q是指向int型数组的指针
    system("pause");
    return 0;
}