/*
*File : ch13/13.1/class.h
*Date : 2022-08-08
*Page : 443
*/

#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

class Foo {
public:
    Foo& operator=(const Foo&);
};

class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const Sales_data&);
    Sales_data& operator=(const Sales_data &);
    ~Sales_data() {}
private:
    std::string bookNo;
    int units_sold;
    double revenue = 0.0;
};

Sales_data::Sales_data(const Sales_data& orig):
    bookNo(orig.bookNo),//使用string的拷贝构造函数
    units_sold(orig.units_sold),//拷贝
    revenue(orig.revenue)//拷贝
    { }

Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}

struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
    X& operator=(const X&);
    ~X() { std::cout << "~X()" << std::endl;}
};

X& X::operator=(const X& rhs)
{
    std::cout << "X::operator=" << std::endl;
    return *this;
}

#endif