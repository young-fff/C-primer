/*
*File : ch09/9.5/str_init.cpp
*Date : 2022-07-28
*Page : 322
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
    vector<char> cvec = {'h' , 'e', 'l', 'l', 'o'};
    string str(cvec.begin(), cvec.end());
    cout << str << endl;

    system("pause");
    return 0;
}