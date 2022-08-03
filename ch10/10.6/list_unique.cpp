/*
*File : ch10/10.6/list_unique.cpp
*Date : 2022-08-03
*Page : 370
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<int> ilst{1, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 1, 2, 4};
    ilst.sort();
    ilst.unique();

    for (auto i : ilst)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}