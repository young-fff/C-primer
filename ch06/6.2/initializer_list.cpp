/*
*File : ch06/6.2/initializer_list.cpp
*Date : 2022-07-15
*Page : 198
*/

#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

int int_sum(initializer_list<int> il)
{
    int res = 0; 
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        res += *beg;
    return res;
}
int main()
{
    string expected{"apple"};
    string actual{"banana"};
    if (expected != actual)
        error_msg({"functionX", expected, actual});
    else
        error_msg({"functionX", "okay"});
    int i = 1, j = 2, k = 3;
    int res = int_sum({i,j,k});
    cout << res << endl;
    system("pause");
    return 0;
}