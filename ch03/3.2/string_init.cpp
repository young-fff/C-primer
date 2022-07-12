/*
*File : ch03/3.2/string_init.cpp
*Date : 2022-07-12
*Page : 76
*/

#include <iostream>
using namespace std;

int main()
{
    string s1;
    string s2 = s1;
    string s3 = "hiya";     //拷贝初始化
    string s4(10,'C');      //直接初始化
    string s5("hiya");      //直接初始化
    return 0;
}