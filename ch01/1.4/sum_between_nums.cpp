/*
*File : ch01/1.4/sum_between_nums.cpp
*Date : 2022-07-10
*Page : 11
*/

#include<iostream>

int main()
{
    std::cout<<" Enter two numbers : ";
    int sum = 0, val1 = 0 ,val2 = 0;
    std::cin >> val1 >> val2;
    //只要val的值大于等于1，while循环就会继续执行
    while(val2 >= val1){
        sum += val2;     //将sum + val赋予sum
        --val2;          //将val减1
    }
    std::cout << "Sum of val2 to val1 inclusive is "
            << sum << std::endl;
    //system("pause");
    return 0;
}