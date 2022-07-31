/*
*File : ch10/10.3/compareIsbn.cpp
*Date : 2022-07-31
*Page : 344
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <numeric>
#include <iterator>
#include "Sales_data.h"

using namespace std;

bool CompareIsbn(const Sales_data& sale1, const Sales_data& sale2)
{
    return sale1.isbn().size() < sale2.isbn().size();
}

int main()
{
    vector<Sales_data> sale_vec;
    string bookNo = "";
    for (int i = 0; i < 5; i++) {
        bookNo += "s";
        cout << bookNo << endl;
        sale_vec.push_back(Sales_data(bookNo));
    }
    for (auto i : sale_vec) {
        print(cout, i);
    }
    //sort(sale_vec.begin(), sale_vec.end(), CompareIsbn);
    sort(sale_vec.begin(), sale_vec.end(), 
        [](const Sales_data &sale1, const Sales_data &sale2) {return sale1.isbn().size() < sale2.isbn().size();});
    for (auto i : sale_vec)
        print(cout, i);
    system("pause");
    return 0;
}