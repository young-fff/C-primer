/*
*File : ch12/12.2/allocator.cpp
*Date : 2022-08-07
*Page : 427
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>
#include <string.h>


using namespace std;


int main()
{
    int n = 2;
    string *const p = new string[n]; //构建n个空string
    string s;
    string *q = p;
    while (cin >> s && q != p + n)
        *q++ = s;
    const size_t size = p - q;
    delete [] p;
    
    allocator<string> alloc;    //可以分配string的allocator对象
    auto const p = alloc.allocate(n);   //分配n个未初始化的string
    
    //allocator分配未构造的内存
    auto q = p;
    alloc.construct(q++);           //*q为空字符串
    alloc.construct(q++, 10, 'c');  //*q为cccccccccc
    alloc.construct(q++, "hi");     //*q为hi

    cout << *p << endl; //正确：使用string的输出运算符
    //cout << *q << endl; //灾难：q指向未构造的内存

    while (q != p)
        alloc.destroy(--q);

    //拷贝和填充未初始化内存
    vector<int> vi{1,2,3,4,5};
    //分配比vi中元素所占的空间大一倍的空间
    auto p = alloc.allocate(vi.size() * 2);
    //通过拷贝vi中元素来构造从p开始的元素
    auto q = uninitialized_copy(vi.begin(), vi.end(), p);
    //将剩余元素全部初始化为42
    uninitialized_fill_n(q, vi.size(), 42);

    allocator<string> alloc2;
    auto const p = alloc.allocate(10);
    string s;
    auto q = p;
    while (cin >> s && q != p + 10)
        alloc2.construct(q++, s);
    while (q != p) {
        cout << *--q << endl;
        alloc2.destroy(q);
    }
    alloc2.deallocate(p, 10);

    system("pause");
    return 0;
}