/*
*File : ch13/13.2/HasPtr_val.h
*Date : 2022-08-08
*Page : 453
*/

#ifndef HASPTR_VAL_H
#define HASPTR_VAL_H

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) { }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr() {delete ps;}
private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

#endif