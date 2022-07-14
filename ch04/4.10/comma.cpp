/*
*File : ch04/4.10/comma.cpp
*Date : 2022-07-14
*Page : 140
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v{1,2,3,4};
    auto cnt = v.size();
    for (auto i = 0; i != v.size(); ++i, --cnt)
        v[i] = cnt;
    for (auto i : v) 
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}