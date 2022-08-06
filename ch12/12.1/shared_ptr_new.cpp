/*
*File : ch12/12.1/shared_ptr_new.cpp
*Date : 2022-08-06
*Page : 412
*/

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>

using namespace std;

shared_ptr<int> clone(int p)
{
    //return new int(p);     //错误：禁止隐式转换为shared_ptr<int>
    return shared_ptr<int>(new int(p));
}

void process(shared_ptr<int> ptr)
{
    //使用ptr
}  //离开作用域ptr被销毁

int main()
{
    shared_ptr<double> p1;
    shared_ptr<int> p2(new int(42));

    //shared_ptr<int> p1 = new int(1024); //必须使用直接初始化
    shared_ptr<int> p2(new int(1024));

    shared_ptr<int> p(new int(42)); //引用计数为1
    process(p); //process中引用计数为2
    int i = *p; //引用计数为1
    
    int *x(new int(1024));
    //process(x); //错误：不能将int* 转换成一个shared_ptr<int>
    process(shared_ptr<int>(x)); //合法，但内存会被释放
    int j = *x; //未定义的，x是一个空悬指针

    //使用get
    shared_ptr<int> p(new int(42));
    int *q = p.get();   //正确，但要注意不要让它管理的指针被释放
    {
        //未定义：两个独立的shared_ptr指向相同的内存
        shared_ptr<int>(q);
    }   //程序快结束，q被销毁，指向的内存被释放
    int foo = *p;   //未定义：p指向的内存已经被释放了

    //p = new int(1024);//错误：不能将一个指针赋予shared_ptr
    p.reset(new int(1024));//正确p指向一个新对象
    
    shared_ptr<string> ps(new string("hello"));
    string newVal = "world";
    if(!ps.unique())
        ps.reset(new string(*ps)); //不是唯一用户，分配新的拷贝
    *ps += newVal;   //此时是唯一用户，可以改变对象的值

    system("pause");
    return 0;
}