/*
*File : ch01/1.5/check_item.cpp
*Date : 2022-07-10
*Page : 20
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1,item2;
    std::cin >> item1 >> item2;
    //检查是否相同
    if (item1.isbn() == item2.isbn())
    {
        std::cout << item1 + item2 << std::endl;
        return 0;   //表示成功
    }else{
    std::cerr << "Data must refer to same ISBN"<< std::endl;
    return -1;      //表示失败   
    }
}