/*
*File : ch06/7.1/Sales_data.cpp
*Date : 2022-07-16
*Page : 230
*/

#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"
using namespace std;


int main()
{
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
    system("pause");
    return 0;
}