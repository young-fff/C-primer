/*
*File : ch15/15.3/virtual.cpp
*Date : 2022-08-16
*Page : 537
*/

#include <string>
#include <iostream>
#include "override.h"

int main()
{
    Quote base("0-201-82470-1", 50);
    print_total(cout, base, 10);
    Bulk_quote derived("0-201-82470-1", 50, 5, 0.19);
    print_total(cout, derived, 10);

    system("pause");
    return 0;
}

