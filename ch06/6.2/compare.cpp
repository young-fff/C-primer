/*
*File : ch06/6.2/compare.cpp
*Date : 2022-07-15
*Page : 196
*/

#include <iostream>
#include <string>
using namespace std;

int bigger(int ival, const int* pval)
{
    return ((ival > *pval) ? ival : *pval);
}

int main()
{
    int val1 = 8;
    int val2 = 9;
    int *p = &val2;
    cout << "Bigger one is : " << bigger(val1, p) << endl;
    system("pause");
    return 0;
}