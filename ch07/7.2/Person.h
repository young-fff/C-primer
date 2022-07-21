/*
*File : ch06/7.2/Person.h
*Date : 2022-07-17
*Page : 233
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

struct person {
    friend istream &read(istream &is, person per);
    friend ostream &print(ostream &os, const person per);
    public:
        person() = default;
        explicit person(const string &n) : name(n) { };
        person(const string &n, const string &a) : name(n), addr(a) { };
        person(istream &is) {read(is, *this);}
        //get_name和getaddr都不改变对象的值，故用const
        string get_name() const {return name;}
        string get_addr() const {return addr;}

    private:
        string name;
        string addr;
};

istream &read(istream &is, person per);
ostream &print(ostream &os, const person per);

istream &read(istream &is, person per)
{
    is >> per.name >> per.addr;
    return is;
}

ostream &print(ostream &os, const person per)
{
    os << per.name << " " << per.addr;
    return os;
}

#endif