/*
*File : ch06/7.5/nodefault.cpp
*Date : 2022-07-21
*Page : 262
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NoDefault {
public:
    NoDefault(const string&);
    //还有其他成员，但没有其他构造函数了
    NoDefault(int i) : imem(i) { }
    int imem;
};
struct A { //my_mem默认为public
    NoDefault my_mem;
};
A a;    //不能为A合成构造函数
struct B {
    //B() {} //b_member无初始值
    NoDefault b_member;
};
struct C {
    C() : c_mem(0) { }
    NoDefault c_mem;
};

vector<NoDefault> vec(10); //Nodefault未提供默认构造函数，且vec的十个元素未初始化