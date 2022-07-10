/*
*File : ch01/1.4/if_sum_between_nums.cpp
*Date : 2022-07-10
*Page : 16
*/

#include<iostream>

int main()
{
    std::cout<<" Enter two numbers : ";
    int sum = 0, val1 = 0 ,val2 = 0;
    std::cin >> val1 >> val2;
    if ( val1 > val2 ){
        int temp = val1;
        val1 = val2;
        val2 = temp;
    }
    while(val2 >= val1){
        sum += val2;    
        --val2;        
    }
    std::cout << "Sum of val2 to val1 inclusive is "
            << sum << std::endl;
    system("pause");
    return 0;
}