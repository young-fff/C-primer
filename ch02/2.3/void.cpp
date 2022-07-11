/*
*File : ch02/2.3/void.cpp
*Date : 2022-07-11
*Page : 50
*/

#include<iostream>
#include<stdlib.h>

int main()
{
    double *base = (double*) malloc(sizeof(int)*10);
    std::cout << base << std::endl;
    system("pause");
    return 0;
}