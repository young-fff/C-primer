/*
*File : ch13/13.5/rvalue_ref.cpp
*Date : 2022-08-10
*Page : 471
*/

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <new>
#include <set>
#include <utility>

int main()
{
    int i = 42;
    int &r = i;
    //int &&rr = i;
    //int &r2 = i * 42;
    const int &r3 = i * 42;
    int &&rr2 = i * 42;

    int &&rr1 = 42;
    //int &&rr2 = rr1;

    int &&rr3 = std::move(rr1);

    system("pause");
    return 0;
}

