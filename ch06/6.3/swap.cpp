/*
*File : ch06/6.3/string_par.cpp
*Date : 2022-07-15
*Page : 192
*/

#include <iostream>
#include <string>
using namespace std;

void swap(int &v1, int &v2)
{
    if (v1 == v2)
        return;
    int temp = v2;
    v2 = v1;
    v1 = temp;
}

int main()
{
    
    system("pause");
    return 0;
}