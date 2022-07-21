/*
*File : ch07/7.2/class_sales.h
*Date : 2022-07-18
*Page : 240
*/

#include <iostream>
#include <string>
using namespace std;

class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend ostream &print(ostream&, const Sales_data&);
    friend istream &read(istream&, Sales_data&);
    public:
        //新的构造函数
        //Sales_data() = default;
        Sales_data() : bookNo(""), units_sold(0), revenue(0) { };
        Sales_data(const string &s) : bookNo(s) { }; 
        Sales_data(const string &s, unsigned n, double p) : 
            bookNo(s), units_sold(n), revenue(p * n) { };
        
        //Sales_data(istream &);    //在类外部定义构造函数
        Sales_data(istream &is){read(is, *this);}

        //原先的成员
        string isbn() const {return bookNo;}
        Sales_data& combine(const Sales_data&);

    private:
        double avg_price() const;
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

//类外部定义成员函数应该与声明保持一致，必须包含类名
inline
double Sales_data::avg_price() const 
{ 
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}