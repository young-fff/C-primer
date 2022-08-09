/*
*File : ch13/13.2/HasPtr_ptr.h
*Date : 2022-08-09
*Page : 456
*/

#ifndef HASPTR_PTR_H
#define HASPTR_PTR_H

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) {++*use;}
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr::~HasPtr()
{
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

#endif