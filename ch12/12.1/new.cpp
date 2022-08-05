/*
*File : ch12/12.1/new.cpp
*Date : 2022-08-05
*Page : 407
*/

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

using namespace std;

int main()
{
    //pi指向一个动态分配的、未初始化的无名对象
    int *pi = new int;

    //初始化为空string, pi指向一个未初始化的int
    string *ps = new string;
    int *pi = new int;
    //传统的构造方式
    int *pi = new int(1024);
    string *ps = new string(10, '9');
    //列表初始化
    vector<int> *pv = new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    //值初始化
    string *p1 = new string;//默认初始化为空string
    string *ps = new string();//值初始化为空string
    int *pi1 = new int;//默认初始化，*pi1的值未定义
    int *pi2 = new int();//值初始化为0，*pi2为0

    //使用auto来推断分配的对象类型
    int obj;
    auto p1 = new auto(obj);//p指向一个与obj类型相同的对象，该对象用obj进行初始化
    //auto p2 = new auto{a, b, c}; //括号里只能有单个初始化器

    // 动态分配的const对象
    const int *pci = new const int(1024);
    const string *pcs = new const string;

    //如果分配失败，new返回一个空指针
    int *p1 = new int; //如果分配失败new抛出std::bad_alloc
    int *p2 = new (nothrow) int;//如果分配失败，new返回一个空指针


    system("pause");
    return 0;
}