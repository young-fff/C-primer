/*
*File : ch14/14.1/restore.cpp
*Date : 2022-08-12
*Page : 491
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    //重载operator "+"过后
    //data1 + data2;   普通的表达式
    //operator+(data1, data2); 等价的函数调用
    
    //data1 += data2;  基于调用的表达式
    //data1.operator(data2); 对成员运算符函数的等价调用
    
    string s = "world";
    string t = s + "!";
    string u = "hi" + s;//如果+是string的成员，则产生错误

    system("pause");
    return 0;
}

