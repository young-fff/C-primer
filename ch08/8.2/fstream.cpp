/*
*File : ch08/8.2/buf.cpp
*Date : 2022-07-22
*Page : 284
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sales_data.h"

using namespace std;

int main(int argc, char*argv[])
{
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    } else {
        cerr << ":No data?!" << endl;
    }

//每次进循环都是全新的input 自动析构
    for (auto p = argv + 1; p != argv + argc; ++p) {
        ifstream input(*p);
        if (input) {
            //process(input);
        } else 
            cerr << " coundn't open: " + string(*p);
    }

    system("pause");
}