/*
*File : ch02/2.6/Sales_data.h
*Date : 2022-07-12
*Page : 65
*/

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif