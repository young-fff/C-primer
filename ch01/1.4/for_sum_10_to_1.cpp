/*
*File : ch01/1.4/for_sum_10_to_1.cpp
*Date : 2022-07-10
*Page : 12
*/

#include<iostream>

int main()
{
    int sum = 0;
    for(int val =10 ; val >= 1; --val){
        sum += val;
    }
    std::cout << "Sum of 10 to 1 inclusive is "
            << sum << std::endl;
    //system("pause");
    return 0;
}