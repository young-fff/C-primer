/*
*File : ch10/10.3/partition.cpp
*Date : 2022-07-31
*Page : 345
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

bool isShort(string &str)
{
    return str.size() < 5;
}

int main()
{
    vector<string> words{"aaaaa", "b", "cc", "ddddddd", "eeeeee"};
    auto iter = partition(words.begin(), words.end(), isShort);
    while (iter != words.end()) {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;   
    
    system("pause");
    return 0;
}