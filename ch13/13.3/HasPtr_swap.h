/*
*File : ch13/13.3/HasPtr_swap.h
*Date : 2022-08-09
*Page : 458
*/

#ifndef HASPTR_SWAP_H
#define HASPTR_SWAP_H

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) { }
    //HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(HasPtr);
    ~HasPtr() {delete ps;}
    std::string& getps() {return *ps;}
private:
    std::string *ps;
    int i;
};
/*
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}
*/
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;//说明相较于std版本，更优先用其他匹配版本
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "------swap here------" << std::endl;
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
    std::cout << "------operator= here------" << std::endl;
    swap(*this, rhs);
    return *this;
}


inline bool operator<(HasPtr& lhs, HasPtr& rhs)
{
    return *lhs.ps < *rhs.ps;
}

#endif