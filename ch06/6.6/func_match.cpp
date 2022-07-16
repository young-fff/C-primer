/*
*File : ch06/6.6/func_match.cpp
*Date : 2022-07-16
*Page : 219
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f()
{
    cout << "f ()" <<endl;
}

void f(int ival)
{
    cout << "f ( int )" << endl;
}

void f(int ival1, int ival2)
{
    cout << "f ( int , int )" << endl;
}

void f(double dval1, double dval2 = 3.14)
{
    cout << "f ( double , double )" << endl;
}

int main()
{
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    system("pause");
    return 0;
}