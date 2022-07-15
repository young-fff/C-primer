/*
*File : ch06/6.3/recursion.cpp
*Date : 2022-07-16
*Page : 203
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int factorial(int val)
{
    if (val > 1)
        return factorial(val - 1) * val;
    return 1;
}

int main()
{
    cout << factorial(5) << endl;
    system("pause");
    return 0;
}