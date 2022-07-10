/*
*File : ch01/1.5/reword_num.cpp
*Date : 2022-07-10
*Page : 21
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem , item ;
    //读取第一个记录，并确保确实有数据可以处理
    if (std::cin >> currItem){
        int cnt = 1;
        while (std::cin >> item){
            if (item.isbn() == currItem.isbn())
                ++cnt;
            else {
                std::cout << currItem.isbn() << " occurs "
                << cnt << " times " << std::endl;
                currItem = item;
                cnt = 1;
            }
        }//while 循环在这里结束
        std::cout << currItem.isbn() << " occurs "
        << cnt << " times " << std::endl;
    }//最外层的if在这里结束
    //system("pause");
    return 0;
}