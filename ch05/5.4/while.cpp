/*
*File : ch05/5.4/while.cpp
*Date : 2022-07-14
*Page : 165
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v;
    int i;
    while (cin >> i)
        v.push_back(i);
    auto beg = v.begin();
    while (beg != v.end() && *beg >= 0)
        ++beg;
    if (beg == v.end())
        ;
    system("pause");
    return 0;
}