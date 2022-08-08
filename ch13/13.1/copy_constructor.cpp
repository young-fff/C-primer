/*
*File : ch13/13.1/copy_coonstructor.cpp
*Date : 2022-08-08
*Page : 440
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

using namespace std;

class Foo {
public:
    Foo();
    Foo(const Foo&);
};

class Sales_data {
public:
    Sales_data(const Sales_data&);
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

class HasPtr {
public:
    HasPtr(const HasPtr&); 
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    ~HasPtr() {}
    HasPtr& operator=(const HasPtr&);
private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& rhs)
{
    ps = rhs.ps;
    i = rhs.i;
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    *ps = *(rhs.ps);
    i = rhs.i;
    return *this;
}

int main()
{
    //直接初始化
    string dots(10, '.');
    string s(dots);

    //拷贝初始化
    string s2 = dots;
    string null_book = "9-999-99999-9";
    string nines = string(100, '9');

    vector<int> v1(10);
    //vector<int> v2 = 10;//错误：接受大小参数的构造函数是explicit的
    void f(vector<int>);
    //f(10);//不能用一个int直接构造一个临时vector
    f(vector<int>(10));//从一个int直接构造一个临时vector

    system("pause");
    return 0;
}