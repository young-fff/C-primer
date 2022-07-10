/*
*File : ch01/1.4/for.cpp
*Date : 2022-07-10
*Page : 11
*/

#include<iostream>

int main()
{
    int sum = 0;
    //从1加到10
    for(int val = 1; val <= 10; ++val)
        sum += val;     //等于sum= sum + val
    std::cout << "Sum of 1 to 10 inclusive is "
            << sum << std::endl;
    //system("pause");
    return 0;
}