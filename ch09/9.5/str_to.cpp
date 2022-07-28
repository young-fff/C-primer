/*
*File : ch09/9.5/str_to.cpp
*Date : 2022-07-28
*Page : 328
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <array>

using namespace std;



int main()
{
    vector<string> svec{"120", "20", "60"};
    int isum = 0;
    double dsum = 0;
    for (auto i : svec) {
        isum += stoi(i);
        dsum += stod(i);
    }
    cout << "isum = " << isum << endl;
    cout << "dsum = " << dsum << endl;

    system("pause");
    return 0;
}