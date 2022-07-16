/*
*File : ch06/6.6/func_arg.cpp
*Date : 2022-07-16
*Page : 222
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void useBigger(const string &s1, const string &s2,
    bool pf(const string &, const string &));

void useBigger(const string &s1, const string &s2,
    bool (*pf)(const string &, const string &));

bool lengthCompare(const string &, const string &);

typedef bool func(const string &, const string &);
typedef decltype(lengthCompare) func2;

typedef bool (*funcp)(const string &, const string &);
typedef decltype(lengthCompare) *funcp2;

void useBigger2(const string &s1, const string &s2, func);
void useBigger3(const string &s1, const string &s2, funcp2);

int ifunc(int ival, int jval);
int f1(int i, int j)
{
    return i + j;
}
int f2(int i, int j)
{
    return i - j;
}
int f3(int i, int j)
{
    return i * j;
}
int f4(int i, int j)
{
    return i / j;
}


int main()
{
    vector<decltype(ifunc)*> v;
    v.push_back(f1);
    v.push_back(f2);
    v.push_back(f3);
    v.push_back(f4);
    for (auto f : v)
        cout << f(4, 2) << endl;
    system("pause");
    return 0;
}