/*
*File : ch06/6.1/factfunc.cpp
*Date : 2022-07-15
*Page : 187
*/

#include <iostream>
#include "Chapter6.h"
using namespace std;

int fact (int val) 
{
    int ret = 1;
    while (val > 1) 
        ret *= val--;
    return ret;
}