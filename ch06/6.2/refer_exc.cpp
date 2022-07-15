/*
*File : ch06/6.2/refer_exc.cpp
*Date : 2022-07-15
*Page : 190
*/

#include <iostream>
using namespace std;

void exc(int &p1,int &p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    int i = 42, j = 0;
    exc(i, j);
    cout << "i = " << i << " " << "j = " << j << endl;
    system("pause");
    return 0;
}