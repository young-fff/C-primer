/*
*File : ch06/6.4/overload.cpp
*Date : 2022-07-16
*Page : 210
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string read();
void print(const string &);
void print(double);

void fooBar(int ival)
{
    bool read = false;
    //string s = read();
    void print(int);
    //print("Value: ");
    print(ival);
    print(3.14);
}

int main()
{
    
    system("pause");
    return 0;
}