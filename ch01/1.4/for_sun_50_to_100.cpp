/*
*File : ch01/1.4/for_sum_50_to_100.cpp
*Date : 2022-07-10
*Page : 12
*/

#include<iostream>

int main()
{
    int sum = 0;
    for(int val =50 ; val <= 100; ++val){
        sum += val;
    }
    std::cout << "Sum of 50 to 100 inclusive is "
            << sum << std::endl;
    //system("pause");
    return 0;
}