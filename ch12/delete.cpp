/*
*File : ch12/12.1/delete.cpp
*Date : 2022-08-05
*Page : 409
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
    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;
    //delete i; //错误:i不是一个指针
    delete pi1; //未定义：pi1指向一个局部变量
    delete pd;  //正确
    delete pd2; //未定义：pd2指向的内存已经被释放了
    delete pi2; //正确：释放一个空指针总是没有错误的

    //const对象的值不能被修改，但它本身是可以销毁的
    const int *pci = new const int(1024);
    delete pci;//释放一个const 对象

    //delete内存之后的重置指针方法只对这个指针有效
    int *p(new int (42));   //p指向动态内存
    auto q = p;             //p和q指向相同的内存
    delete p;               //p和q均变为无效
    p = nullptr;            //指出p不在绑定到任何对象
    //事实上q还是指向无效内存，在实际系统中查找指向相同内存的所有指针是异常困难的

    system("pause");
    return 0;
}