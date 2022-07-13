/*
*File : ch03/3.5/array_end.cpp
*Date : 2022-07-13
*Page : 106
*/

#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *pbeg = begin(arr), *pend = end(arr);
    int *end = &arr[10];    //数组尾后元素存在,但不能解引用
    for (int *ind = arr; ind != end; ++ind)
        cout << *ind << endl;
    while (pbeg != pend){
        cout << *pbeg <<endl;
        pbeg++;
    }

    system("pause");
    return 0;
}