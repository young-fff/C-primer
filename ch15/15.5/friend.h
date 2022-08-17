/*
*File : ch15/15.5/friend.h
*Date : 2022-08-17
*Page : 545
*/

#ifndef FRIEND_H
#define FRIEND_H
#include <string>
#include <iostream>

class Base {
    friend class Pal;
public:
    void pub_mem();
    std::size_t size() const {return n;}
protected:
    int prot_mem;
    std::size_t n;
private:
    char priv_mem;
};

class Sneaky : public Base {
    friend void clobber(Sneaky&);
    friend void clobber(Base&);
    int j;
};

class Pal {
public:
    int f(Base b){return b.prot_mem;} 
    //int f2(Sneaky s){return s.j;}
    int f3(Sneaky s){return s.prot_mem;}
};

class D2 : public Pal {
public:
    //int mem(Base b) {return b.prot_mem;}
};

class Derived : private Base {
public:
    using Base::size;
protected:
    using Base::n;
};

#endif