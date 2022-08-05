/*
*File : ch12/12.1/shared_ptr.cpp
*Date : 2022-08-05
*Page : 400
*/

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>

using namespace std;
using std::istringstream;

int main()
{
    shared_ptr<string> p1;
    shared_ptr<list<int>> p2;
    if (p1 && p1 -> empty())
        *p1 = "hi";

//make_shared函数
    shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    shared_ptr<int> p5 = make_shared<int>();
    auto p6 = make_shared<vector<string>>();

//shared_ptr的拷贝或赋值
    auto p = make_shared<int>(42);//p指向的对象只有一个引用者
    auto q(p);//p和q指向相同对象，此对象有两个引用者

    auto r = make_shared<int>(42);//r指向的int只有一个引用者
    r = q;  //给r赋值，令它指向另一个地址
            //递增q指向的对象的引用计数
            //递减r原来指向的对象的对象的引用计数
            //r原来指向的对象已经没有引用者，会自动释放

    vector<string> v1;  //空vector
    {                   //新作用域
        vector<string> v2 = {"a", "an", "the"};
        v1 = v2;        //从v2拷贝元素到v1中
    }                   //v2被销毁，其中的元素也被销毁
                        //v1有三个元素，是原来v2中元素的拷贝

    system("pause");
    return 0;
}