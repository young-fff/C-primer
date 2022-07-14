/*
*File : ch04/4.5/increment.cpp
*Date : 2022-07-14
*Page : 132
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{1,2,3,4,5,-1,-2};
    auto pbeg = v.begin();
    while (pbeg != v.end() && *pbeg >= 0)
        cout << *pbeg++ <<endl;
    
    int ival = 2;
    if (v[ival++] <= v[ival]) {
        cout << "yes" << endl;
    } 
    system("pause");
    return 0;
}