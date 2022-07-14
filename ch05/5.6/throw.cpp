/*
*File : ch05/5.6/throw.cpp
*Date : 2022-07-15
*Page : 173
*/

#include <iostream>
#include <vector>
#include <string>
#include "Sales_item.h"
using namespace std;

int main()
{
    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (item1.isbn() != item2.isbn())
        throw runtime_error("Data must refer to same ISBN");
    cout << item1 + item2 << endl; 
    system("pause");
    return 0;
}
