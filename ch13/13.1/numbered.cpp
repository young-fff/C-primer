/*
*File : ch13/13.1/numbered.cpp
*Date : 2022-08-08
*Page : 448
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

using namespace std;

class numbered {
public:
    numbered() {mysn = num++;}
    numbered(const numbered&);
    int mysn;
    static int num;
};

numbered::numbered(const numbered &rhs)
{
    mysn = num++;
}

void f (const numbered &s)
{
    cout << s.mysn << endl;
}

int numbered::num = 0;

int main()
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);

    system("pause");
    return 0;
}