/*
*File : ch06/6.6/func_ptr.cpp
*Date : 2022-07-16
*Page : 219
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool lengthCompare(const string &, const string &);
bool (*pf)(const string &, const string &);
string::size_type sumLength(const string&, const string&);
bool cstringCompare(const char*, const char*);
int main()
{
    auto pf1 = lengthCompare;
    auto pf2 = &lengthCompare;

    bool b1 = pf("hello", "goodbye");
    bool b2 = (*pf)("hello", "goodbye");
    bool b3 = lengthCompare("hello", "goodbye");


    pf = 0;
    //pf = sumLength; 
    //pf = cstringCompare;
    //pf = lengthCompare;
    //函数和指针类型必须精确匹配
    system("pause");
    return 0;
}