/*
*File : ch03/3.2/str_cmp.cpp
*Date : 2022-07-12
*Page : 80
*/

#include <iostream>
using namespace std;

int main()
{
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";

    cout << (str < phrase) <<endl; 
    cout << (str < slang) <<endl;
    system("pause");
    return 0;
}