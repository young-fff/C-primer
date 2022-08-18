/*
*File : ch15/15.6/virtual.h
*Date : 2022-08-18
*Page : 550
*/

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include <string>
#include <iostream>

class Base {
public:
    virtual int fcn();
};

class D1 : public Base {
public:
    int fcn(int);
    virtual void f2();
};

class D2 : public D1 {
public:
    int fcn(int);
    int fcn();
    void f2();
};

#endif