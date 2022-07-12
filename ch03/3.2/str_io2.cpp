/*
*File : ch03/3.2/string_io2.cpp
*Date : 2022-07-12
*Page : 78
*/

#include <iostream>
using namespace std;

int main()
{
    string word;
    int i = 0;
    while (cin >> word)
        cout << "Line" << ++i  << ": " << word << endl;
    system("pause");
    return 0;
}