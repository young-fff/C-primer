/*
*File : ch09/9.2/assignment.cpp
*Date : 2022-07-27
*Page : 302
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
    array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> a2 = {0};
    a1 = a2;
    //a2 = {0};   //  不能将花括号列表赋值给数组

    list<string> names;
    vector<const char*> oldstyle;
    //names = oldstyle; //  类型不匹配
    names.assign(oldstyle.begin(), oldstyle.end());

    list<string> slist1(1);
    slist1.assign(10, "Hiya!");

    vector<string> svec1(10);
    vector<string> svec2(24);
    swap(svec1, svec2);

    list<char*> lchar;
    vector<string> vs;
    vs.assign(lchar.begin(), lchar.end());

    system("pause");
    return 0;
}