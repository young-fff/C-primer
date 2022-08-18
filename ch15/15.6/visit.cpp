/*
*File : ch15/15.6/visit.cpp
*Date : 2022-08-18
*Page : 550
*/

#include <string>
#include <iostream>
#include "virtual.h"

int main()
{
    Base bobj; D1 d1obj; D2 d2obj;
    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1 -> fcn();
    bp2 -> fcn();
    bp3 -> fcn();

    D1 *d1p = &d1obj; D2 *d2p = &d2obj;
    //bp2 -> f2();
    d1p -> f2();
    d2p -> f2();

    Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
    //p1 -> fcn(42);
    p2 -> fcn(42);
    p3 -> fcn(42);

    system("pause");
    return 0;
}

