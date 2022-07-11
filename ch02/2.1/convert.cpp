/*
*File : ch02/2.1/convert.cpp
*Date : 2022-07-11
*Page : 32
*/

#include <iostream>

int main()
{
    bool b = 42;    //b为真
    std::cout << "b = " << b << std::endl;

    int i = b;  //i的值为1
    std::cout << "i = " << i << std::endl;
    
    i = 3.14;   //i的值为3
    std::cout << "i = " << i << std::endl;
    
    double pi = i;  //pi的值为3.0
    std::cout << "pi = " << pi << std::endl;
    
    unsigned char c = -1;   //假设char占8比特，c的值为255
    std::cout << "c = " << c << std::endl;
    system("pause");
    return 0;
    
}