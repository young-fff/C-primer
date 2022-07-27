/*
*File : ch09/9.2/relation.cpp
*Date : 2022-07-27
*Page : 305
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
    vector<int> ivec1(10, 5);
    vector<int> ivec2(10, 4);
    vector<int> ivec3(10, 5);
    cout << "ivec1" << (ivec1 == ivec2 ? " == " : " != ") << "ivec2" << endl;
    cout << "ivec1" << (ivec1 == ivec3 ? " == " : " != ") << "ivec3" << endl;

    list<int> ilist(10, 5);
    vector<int> ivec4(ilist.begin(), ilist.end());
    cout << "ivec1" << (ivec1 == ivec4 ? " == " : " != ") << "ilist4" << endl;
    system("pause");
    return 0;
}