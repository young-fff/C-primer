/*
*File : ch06/6.3/range_get.cpp
*Date : 2022-07-16
*Page : 205
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int &get(int *array, int index)
{
    return array[index];
}

int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
    for (auto i : ia)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}