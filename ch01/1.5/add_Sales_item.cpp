/*
*File : ch01/1.5/add_Sales_item.cpp
*Date : 2022-07-10
*Page : 19
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1,item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;
    //system("pause");
    return 0;
}