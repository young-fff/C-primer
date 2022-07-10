/*
*File : ch01/1.5/add_items.cpp
*Date : 2022-07-10
*Page : 20
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1,item2,item3,item4;
    std::cin >> item1 >> item2 >> item3 >> item4;
    std::cout << item1 + item2 + item3 + item4 << std::endl;
    //system("pause");
    return 0;
}