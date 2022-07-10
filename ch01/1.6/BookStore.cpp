/*
*File : ch01/1.6/Book_Store.cpp
*Date : 2022-07-10
*Page : 21
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total; //保存下一条销售记录
    //读取第一个记录，并确保确实有数据可以处理
    if (std::cin >> total){
        Sales_item trans; //保存的变量
        // 读入并处理剩余交易记录
        while (std::cin >> trans){
            if (total.isbn() == trans.isbn())
                total += trans; //更新销售总额
            else {
                // 打印前一本书的的结果
                std::cout << total << std::endl;
                total = trans; //total现在表示下一本书的销售额
            }
        }
        std::cout << total << std::endl; //打印最后一本书的结果
    }else{
        //没有输入，警告读者
    std::cerr << "No data?!" << std::endl;
    return -1;
    }
    //system("pause");
    return 0;
}