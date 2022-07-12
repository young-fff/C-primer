/*
*File : ch03/3.2/size_type.cpp
*Date : 2022-07-12
*Page : 79
*/

#include <iostream>
using namespace std;

int main()
{
    string s("hello world!");
    auto len = s.size();
    cout << len << endl;
    int n = -1;
    cout << (n < len) <<endl;   //说明len是一个无符号数
    system("pause");
    return 0;
}