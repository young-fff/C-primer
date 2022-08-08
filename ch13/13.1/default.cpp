/*
*File : ch13/13.1/default.cpp
*Date : 2022-08-08
*Page : 449
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

using namespace std;

class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const Sales_data&) = default;
    Sales_data& operator=(const Sales_data&);
    ~Sales_data() = default;
};

Sales_data& Sales_data::operator=(const Sales_data&) = default;

struct Nodtor {
    Nodtor() = default;
    ~Nodtor() = delete;
};

class PrivateCopy {
    PrivateCopy(const PrivateCopy&);
    PrivateCopy &operator=(const PrivateCopy&);
public:
    PrivateCopy() = default;
    ~PrivateCopy();
};

class Employee {
public:
    Employee() = default;
    Employee(const string& s) : name(s) {Emp_no = ++num;}
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
    ~Employee(){}
private:
    string name;
    int Emp_no;
    static int num;
};

Employee::Employee()
{
    Emp_no = ++num;
}

int main()
{
    //Nodtor nd;
   // Nodtor *p = new Nodtor();
    //delete p;

    system("pause");
    return 0;
}