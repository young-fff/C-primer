/*
*File : ch01/1.4/sum_10_to_1.cpp
*Date : 2022-07-10
*Page : 11
*/

#include<iostream>

int main()
{
    int sum = 0, val = 10;
    //只要val的值大于等于1，while循环就会继续执行
    while(val >= 1){
        sum += val;     //将sum + val赋予sum
        --val;          //将val减1
    }
    std::cout << "Sum of 10 to 1 inclusive is "
            << sum << std::endl;
    //system("pause");
    return 0;
}