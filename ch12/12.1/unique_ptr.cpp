/*
*File : ch12/12.1/unique_ptr.cpp
*Date : 2022-08-06
*Page : 417
*/

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>

using namespace std;

//可以拷贝或赋值一个将要销毁的unique_ptr
unique_ptr<int> clone(int p)
{
    return unique_ptr<int>(new int(p));
}

unique_ptr<int> clone2(int p)
{
    unique_ptr<int> ret(new int(p));
    return ret;
}

int main()
{
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(42));

    unique_ptr<string> p11(new string("Stegosaurus"));
    //unique_ptr<string> p2(p1); //unique_ptr不支持拷贝
    unique_ptr<string> p3;
    //unique_ptr<int> p4(p2);
    //p4 = p2;//错误：unique_ptr不支持赋值

    //使用release或reset将指针的所有权从一个unique_ptr转移给另一个unique_ptr
    unique_ptr<string> p22(p11.release());
    unique_ptr<string> p33(new string("Trex"));
    p22.reset(p33.release());

    //p2.release(); //错误：p2不会释放内存，而且我们丢失了指针
    auto p = p2.release();//正确:但必须记得delete(p)



    system("pause");
    return 0;
}