/*
*File : ch06/7.3/class_class.cpp
*Date : 2022-07-19
*Page : 250
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class X;
class Y;

class X{
    friend void f(){}   //  友元的作用是影响访问权限，而不是作为普通意义上的声明
    X() {f();}      //错误：f未被声明
    void g();
    void h();
    Y *y;
};

void X::g(){return f();}    //错误：f未被声明
void f();                      
void X::h(){return f();}    //正确：已声明

class Y{
    X x;
};