/*
*File : ch12/12.1/error.cpp
*Date : 2022-08-06
*Page : 415
*/

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>

using namespace std;

void f()
{
    shared_ptr<int> sp(new int(42));//分配一个对象
    //抛出一个异常，且未在f中被捕获
}   //在函数结束时shared_ptr自动释放内存

void f2()
{
    int *ip = new int(42);//动态分配一个新对象
    //抛出一个异常，且未在f中被捕获
    delete ip; //在退出前释放内存
}

int main()
{
    

    system("pause");
    return 0;
}