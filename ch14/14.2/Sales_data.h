/*
*File : ch14/14.1/Sales_data.h
*Date : 2022-08-12
*Page : 493
*/

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    std::string isbn() const
    {
        return bookNo;
    }
    double avg_price() const
    {
        return revenue;
    }
    Sales_data& combine(const Sales_data& rhs);
    Sales_data& Sales_data::operator+= (const Sales_data& s);
    Sales_data& operator-=(const Sales_data &s);
};

std::istream& operator>> (std::istream& is, Sales_data& s)
{
    double price;
    is >> s.bookNo >> s.units_sold >> price;
    if (is)
        s.revenue = price * s.units_sold;
    else 
        s = Sales_data();
    return is;
}

std::ostream& operator<< (std::ostream& os, Sales_data& s)
{

    os << s.isbn() << "\t" << s.units_sold << "\t" << s.revenue << "\t" << s.avg_price();
}

#endif