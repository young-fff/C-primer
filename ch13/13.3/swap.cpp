/*
*File : ch13/13.3/swap.cpp
*Date : 2022-08-09
*Page : 458
*/


#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>
#include <algorithm>
#include "HasPtr_swap.h"

using namespace std;

int main()
{
    HasPtr hp1("hello");
    HasPtr hp2("world");
    swap(hp1, hp2);
    cout << hp1.getps() << endl;
    cout << hp2.getps() << endl;

    HasPtr hp3("Bob");
    vector<HasPtr> hvec;
    hvec.push_back(hp1);
    hvec.push_back(hp2);
    hvec.push_back(hp3);
    sort(hvec.begin(), hvec.end());
    for (auto i : hvec)
        cout << i.getps() << endl;

    system("pause");
    return 0;
}