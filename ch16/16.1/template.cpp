/*
*File : ch16/16.1/template.cpp
*Date : 2022-08-19
*Page : 578
*/

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

template <typename T> 
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template <typename T> T foo(T* p)
{
    T tmp = *p;
    return tmp;
}  

template <typename T, class U> T calc(const T&, const U&);


template <unsigned N, unsigned M> int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}


template <typename T> inline T min(const T&, const T&);

/*
template <typename T> int compare(const T &v1, const T &v2)
{
    if (less<T>(v1, v2)) return -1;
    if (less<T>(v2, v1)) return 1;
    return 0;
}*/

template <typename T, class U> T find(T b, T e, const U &v)
{
    for ( ; b != e; ++b) {
        if (*b == v)
            return b;
    }
    return e;
}

int main()
{
    cout << compare(1, 0) << endl;

    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl;

    //cout << compare("hi", "mom") << endl;

    system("pause");
    return 0;
}

