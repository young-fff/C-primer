/*
*File : ch08/8.2/new_Sales_data.cpp
*Date : 2022-07-22
*Page : 285
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sales_data.h"

using namespace std;


int main(int argc, char* argv[])
{
    ifstream ifs(argv[1]);
    if (ifs) {
        Sales_data total;
        if (read(ifs, total)) {
            Sales_data trans;
            while (read(ifs, trans)) {
                if (total.isbn() == trans.isbn())
                    total.combine(trans);
                else {
                    print(cout, total) << endl;
                    total = trans;
                }
            }
            print(cout, total) << endl;
        } else {
            cerr << "No Data?!" << endl;
        }
    } else {
        cout << " file name error? " << endl;
    }
    system("pause");
    return 0;
}