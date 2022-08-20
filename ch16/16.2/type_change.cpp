/*
*File : ch16/16.1/template.cpp
*Date : 2022-08-20
*Page : 601
*/

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

template <typename T> T fobj(T, T);
template <typename T> T fref(const T&, const T&);

template <typename T1, typename T2, typename T3> T1 alternative_sum(T2, T3);

template <typename It> auto fcn(It beg, It end) -> decltype(*beg)
{
    return *beg;
}

int main()
{
    string s1("a value");
    const string s2("another value");
    fobj(s1, s2);
    fref(s1, s2);

    int a[10], b[42];
    fobj(a, b);
    //fref(a, b);

    int i;
    long lng;
    auto val2 = alternative_sum<long long, int, long>(i, lng);

    vector<int> vi = {1, 2, 3, 4, 5};
    auto &i = fcn(vi.begin(), vi.end());

    system("pause");
    return 0;
}

