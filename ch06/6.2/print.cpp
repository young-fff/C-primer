/*
*File : ch06/6.2/print.cpp
*Date : 2022-07-15
*Page : 194
*/

#include <iostream>
#include <string>
using namespace std;

//使用标准库规范
void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

//显示传递一个表示数组大小的形参
void print2(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}

//引用形参绑定到对应实参上
void print3(int (&arr)[10])
{
    for (auto elem : arr)
        cout << elem << endl;
}

int main()
{
    int j[2] = {0, 1};
    int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(begin(j), end(j));
    print2(begin(j), end(j)-begin(j));
    print3(k);
    system("pause");
    return 0;
}