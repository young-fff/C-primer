/*
*File : ch13/13.1/copy_operator.cpp
*Date : 2022-08-08
*Page : 443
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>
#include "class.h"

using namespace std;

void f (X& x1, X* x2)
{
    vector<X> xvec;
    xvec.push_back(x1);
    xvec.push_back(*x2);
    cout << "------- destructor in f -----" << endl;
}

void test()
{
    cout << "------- constructor -----" << endl;
    X x1;
    X *x2 = new X();
    cout << "------- copy constructor -----" << endl;
    f (x1, x2);
    cout << "------- destructor 1-----" << endl;
    delete x2;
    cout << "------- destructor 2-----" << endl;
}

int main()
{
/*
    Sales_data *p = new Sales_data;
    auto p2 = make_shared<Sales_data>();
    Sales_data item(*p);
    vector<Sales_data> vec;
    vec.push_back(*p2);
    delete p;
*/
    test();

    system("pause");
    return 0;
}