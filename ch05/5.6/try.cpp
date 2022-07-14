/*
*File : ch05/5.6/try.cpp
*Date : 2022-07-15
*Page : 174
*/

#include <iostream>
#include <vector>
#include <string>
#include "Sales_item.h"
using namespace std;

int main()
{
    Sales_item item1, item2;
    while (cin >> item1 >> item2) {
        try {
            if (item1.isbn() != item2.isbn())
                throw runtime_error("Data must refer to same ISBN");
            cout << item1 + item2 << endl; 
        } catch (runtime_error) {
            cout << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    system("pause");
    return 0;
}
