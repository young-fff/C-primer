/*
*File : ch01/1.4/sum_50_to_100.cpp
*Date : 2022-07-10
*Page : 11
*/

#include<iostream>

int main()
{
    int sum = 0, val = 50;
    //只要val的值小于等于100，while循环就会继续执行
    while(val <= 100){
        sum += val;     //将sum + val赋予sum
        ++val;          //将val加1
    }
    std::cout << "Sum of 50 to 100 inclusive is "
            << sum << std::endl;
    //system("pause");
    return 0;
}