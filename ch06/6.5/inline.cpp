/*
*File : ch06/6.5/inline.cpp
*Date : 2022-07-16
*Page : 214
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}


inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
/*
//传入的参数不是字面值，返回值是bool型变量，不是字面值常量
constexpr bool isShorter2(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
*/
int main()
{
    system("pause");
    return 0;
}