/*
*File : ch06/6.4/const_cast.cpp
*Date : 2022-07-16
*Page : 209
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
    auto &res = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
    return const_cast<string&>(res);
}

int main()
{
    
    system("pause");
    return 0;
}