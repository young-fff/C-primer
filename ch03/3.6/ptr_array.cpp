/*
*File : ch03/3.5/ptr_array.cpp
*Date : 2022-07-13
*Page : 115
*/

#include <iostream>
//typedef int int_array[4];
using int_array = int[4];
using namespace std;

int main()
{
    int ia[3][4] = {{1, 2, 3, 4},{ 5, 6, 7, 8},{ 9, 10, 11, 12}}; 
    int ( *p)[4] = ia;
    //ia和p打印的是{1，2，3，4}的地址，而ia[0]打印的是1的地址
    cout << ia << " : " << ia[0] << " : " << p << endl;

    p = &ia[2];
    //p 的类型是指向数组的指针，ia[2]是指向int 的指针
    cout << p << " : " << ia[2] << endl;

    for (auto p = begin(ia); p != end(ia); ++p){
        for (auto q = begin(*p); q != end(*p); ++q){
            cout << *q << " ";
        }
        cout << endl;
    }

    for (int_array *p = ia; p != ia +3; ++p){
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }
    system("pause");
    return 0;
}