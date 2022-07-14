/*
*File : ch04/4.4/get_value.cpp
*Date : 2022-07-14
*Page : 130
*/

#include <iostream>
using namespace std;

int main()
{
/*
    int i = get_value();
    while (i != 42) {
        //
        i = get_value();
    }

    int i;
    while ((i = get_value()) != 42) {
        //
    }
*/

    int i; double d;
    d = i = 3.5;
    cout << "d= " << d << "   i= " << i << endl;
    i = d = 3.5;
    cout << "d= " << d << "   i= " << i << endl;

    //double dval; int ival; int *pi;
    //dval = ival = pi = 0;     //不能把int* 类型的pi 赋值给ival

    system("pause");
    return 0;
}