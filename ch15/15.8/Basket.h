/*
*File : ch15/15.8/Basket.h
*Date : 2022-08-18
*Page : 560
*/

#ifndef BASKET_H
#define BASKET_H
#include <string>
#include <iostream>
#include <memory>
#include <set>
#include "move.h"

class Basket {
public:
    void add_item(const std::shared_ptr<Quote> &sale)
    {
        items.insert(sale);
    }
    double total_receipt(std::ostream&) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
        const std::shared_ptr<Quote> &rhs)
    {
        return lhs -> isbn() < rhs -> isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)* > items{compare};
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    return ;  
}

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
}

#endif