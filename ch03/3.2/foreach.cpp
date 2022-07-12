/*
*File : ch03/3.2/foreach.cpp
*Date : 2022-07-12
*Page : 83
*/

#include <iostream>
using namespace std;

int main()
{
    string str = "HelloWorld";
    for (auto c: str)
        cout << c << endl;
    system("pause");
    return 0;
}