/*
*File : ch06/6.2/refer_par.cpp
*Date : 2022-07-15
*Page : 189
*/

#include <iostream>
#include <string>
using namespace std;

void reset(int &i)
{
    i = 0;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
int main()
{
    int j = 42;
    reset(j);
    cout << "j = " << j << endl;

    string str1{"abc"};
    string str2{"abcd"};
    cout << str1 << (isShorter(str1, str2) ? " is " : " is not ") << " shorter than " << str2 << endl;
    system("pause");
    return 0;
}