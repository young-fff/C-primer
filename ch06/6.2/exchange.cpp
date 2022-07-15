/*
*File : ch06/6.2/exchange.cpp
*Date : 2022-07-15
*Page : 188
*/

#include <iostream>
using namespace std;

void exc(int *p1,int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void exc_ptr(int *&p1,int *&p2)
{
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    int i = 42, j = 0;
    exc(&i, &j);
    cout << "i = " << i << " " << "j = " << j << endl;
    int val1 = 8, val2 = 9;
    int *p1 = &val1, *p2 = &val2;
    exc_ptr(p1, p2);
    cout << "p1= " << *p1 << " " << " p2= " << *p2 << endl;
    system("pause");
    return 0;
}