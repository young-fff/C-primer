/*
*File : ch01/1.4/for_sum_between_nums.cpp
*Date : 2022-07-10
*Page : 12
*/

#include<iostream>

int main()
{
    std::cout<<" Enter two numbers : ";
    int sum = 0, val1 = 0 ,val2 = 0;
    std::cin >> val1 >> val2;
    for(int val =val1 ; val <= val2; ++val){
        sum += val;
    }
    std::cout << "Sum of val2 to val1 inclusive is "
            << sum << std::endl;
    //system("pause");
    return 0;
}