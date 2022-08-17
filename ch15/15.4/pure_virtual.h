/*
*File : ch15/15.4/pure_virtual.h
*Date : 2022-08-17
*Page : 541
*/

#ifndef PURE_VIRTUAL_H
#define PURE_VIRTUAL_H
#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const {return bookNo;}; 
    virtual double net_price(std::size_t n) const {return n * price;}
    virtual void debug() const;
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

void Quote::debug() const
{
    std::cout << "This is Quote class." << std::endl;
    std::cout << "bookNo = " << bookNo << " price = " << price << std::endl;
}

class Base {
public:
    static void statement();
};

class Derived : public Base {
    void f(const Derived&);
};

void Derived::f(const Derived &derived_obj)
{
    //Base::statement();
    //Derived::statement();
    //derived_obj.statement();
    //statement();
}

class Limit_quote : public Quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string& book, double price, std::size_t qty, double disc) : Quote(book, price), max_qty(qty), discount(disc) {}
    double net_price(std::size_t) const override;
    void debug() const override;
private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

void Limit_quote::debug() const
{
    std::cout << "This is Limit_quote class." << std::endl;
    std::cout << " price = " << price << std::endl;
    std::cout << "max_qty = " << max_qty << " discount = " << discount << std::endl;
}

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0; 
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, const std::size_t qty, double disc) : Disc_quote(book, price, qty, disc) { }
    double net_price(std::size_t) const override;
};

using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;  
}

#endif