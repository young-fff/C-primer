/*
*File : ch15/15.5/accessible.h
*Date : 2022-08-17
*Page : 543
*/

#ifndef ACCESSIBLE_H
#define ACCESSIBLE_H
#include <string>
#include <iostream>

class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

class Sneaky : public Base {
    friend void clobber(Sneaky&);
    friend void clobber(Base&);
    int j;
};

void clobber(Sneaky &s) {s.j = s.prot_mem = 0;}

//void clobber(Base &b) {b.prot_mem = 0;}

struct Pub_Derv : public Base {
    int f() {return prot_mem;}
    //char g() {return priv_mem;}
};

struct Priv_Derv : private Base {
    int f1() const {return prot_mem;}
};

struct Derived_from_Public : public Pub_Derv {
    int use_base() {return prot_mem;}
};

struct Derived_from_Private : public Priv_Derv {
    //int use_base() {return prot_mem;}
};

#endif