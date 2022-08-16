/*
*File : ch15/15.1/Quote.h
*Date : 2022-08-15
*Page : 526
*/

#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>

class Quote {
public:
    std::string isbn() const;
    virtual double net_price(std::size_t n) const;
};

class Bulk_quote : public Quote {
public:
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