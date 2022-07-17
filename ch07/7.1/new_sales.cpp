/*
*File : ch07/7.1/new_sales.cpp
*Date : 2022-07-16
*Page : 239
*/

#include <iostream>
#include <string>
#include "new_sales.h"
using namespace std;

int main()
{
    Sales_data item1;
    Sales_data item2("1-2-3-x");
    Sales_data item3("1-2-3-y", 3, 20);
    Sales_data item4(cin);
    cout << "item1 : "; 
    print(cout, item1) << endl;
    cout << "item2 : "; 
    print(cout, item2) << endl;
    cout << "item3 : "; 
    print(cout, item3) << endl;
    cout << "item4 : "; 
    print(cout, item4) << endl;

    system("pause");
    return 0;
}