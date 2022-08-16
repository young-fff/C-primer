/*
*File : ch15/15.2/override.h
*Date : 2022-08-16
*Page : 528
*/

#ifndef OVERRIDE_H
#define OVERRIDE_H
#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const {return bookNo;}; 
    virtual double net_price(std::size_t n) const {return n * price;}
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    Bulk_quote(const std::string &book, double p, const std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) { }
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

class Base {
public:
    static void statement();
};

class Derived : public Base {
    void f(const Derived&);
};

void Derived::f(const Derived &derived_obj)
{
    Base::statement();
    Derived::statement();
    derived_obj.statement();
    statement();
}

class Limit_quote : public Quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string& book, double price, std::size_t qty, double disc) : Quote(book, price), max_qty(qty), discount(disc) {}
    double net_price(std::size_t) const override;
private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;  
}

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif