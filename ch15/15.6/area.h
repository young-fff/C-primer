/*
*File : ch15/15.6/area.h
*Date : 2022-08-18
*Page : 548
*/

#ifndef AREA_H
#define AREA_H
#include <string>
#include <iostream>

struct Base {
    Base() : mem(0) { }
    int memfcn();
protected:
    int mem;
};

struct Derived : Base {
    Derived(int i) : mem(i) { }
    int get_mem() {return mem;}
    int memfcn(int);
protected:
    int mem;
};

#endif