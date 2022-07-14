/*
*File : ch04/4.11/cast.cpp
*Date : 2022-07-14
*Page : 145
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int i, j;
    double slope = i / j;

    double slope1 = static_cast<double>(j) / i;

    double d;
    void* p = &d;
    double *dp = static_cast<double*>(p);

    const char *pc;
    char *p = const_cast<char*>(pc);

    int *ip;
    char *pc = reinterpret_cast<char*>(ip);
    string str(pc);

    
    system("pause");
    return 0;
}