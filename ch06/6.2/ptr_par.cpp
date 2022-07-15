/*
*File : ch06/6.2/ptr_par.cpp
*Date : 2022-07-15
*Page : 188
*/

#include <iostream>
using namespace std;

void reset(int *ip)
{
    *ip = 0;
    ip = 0;
}

int main()
{
    int i = 42;
    reset(&i);
    cout << "i = " << i << endl;
    system("pause");
    return 0;
}