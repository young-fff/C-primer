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
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data& combine(const Sales_data& rhs);
    Sales_data& Sales_data::operator+= (const Sales_data& s);
    Sales_data& operator-=(const Sales_data &s);
    Sales_data& operator=(const std::string& isbn);
};


Sales_data& operator+ (const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}

Sales_data& Sales_data::operator+= (const Sales_data& s)
{
    units_sold += s.units_sold;
    revenue += s.revenue;
    return *this;
}

Sales_data& Sales_data::operator-=(const Sales_data &s)
{
    units_sold -= s.units_sold;
    revenue -= s.revenue;
    return *this;
}

Sales_data& operator-(const Sales_data& lhs, const Sales_data &rhs)
{
    Sales_data ret (lhs);
    ret -= rhs;
    return ret;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() && 
        lhs.units_sold == rhs.units_sold &&
        lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

Sales_data& Sales_data::operator=(const std::string& isbn)
{
    *this = Sales_data(isbn);
    return *this;
}

#endif