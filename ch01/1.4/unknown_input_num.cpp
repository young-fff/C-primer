/*
*File : ch01/1.4/unknown_input_num.cpp
*Date : 2022-07-10
*Page : 13
*/

#include<iostream>

int main()
{
    int sum = 0, value = 0;
    //读取数据直到遇见文件尾，计算所有读入的值的和
    while(std::cin >> value){
        sum += value; 
    }
    std::cout << "Sum is: "<< sum << std::endl;
    //system("pause");
    return 0;
}