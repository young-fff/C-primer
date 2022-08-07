/*
*File : ch12/12.2/new[].cpp
*Date : 2022-08-07
*Page : 423
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>


using namespace std;

int get_size()
{
    return 1;
}

int main()
{
    //int *pia = new int[get_size()];
    typedef int arrT[42];
    int *p = new arrT;

    int *pia = new int[10];             //10个未初始化的int
    int *pia2 = new int[10]();          //10个值初始化为0的int
    string *psa = new string[10];       //10个空string
    string *psa2 = new string[10]();    //10个空string

    //提供一个元素初始化器的花括号列表
    int *pia3 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //10个string,前4个用给定的初始化器初始化，剩余的进行值初始化
    string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')};

    size_t n = get_size();
    int *pp = new int[n];
    for (int* q = pp; q != pp + n; ++q) 
        cout << *q << endl;

    //char arr[0]; //不能定义长度为0的数组
    char *cp = new char[0];

    //必须使用方括号对释放动态数组
    delete p;
    delete [] pia;

    //智能指针和动态数组
    //unique_ptr
    unique_ptr<int[]> up(new int[10]);
    up.release();   //自动用delete[]销毁其指针

    //shared_ptr不直接支持管理动态数组，如果希望使用，必须提供自己定义的删除器
    shared_ptr<int> sp(new int[10], [](int *p) {delete [] p;});
    sp.reset();     //使用我们提供的lambda释放数组，它使用delete[]

    //shared_ptr未定义下标运算符，并且不支持指针的算术运算
    for (size_t i = 0; i != 10; ++i)
        *(sp.get() + i) = i;//使用get获取一个内置指针

    system("pause");
    return 0;
}