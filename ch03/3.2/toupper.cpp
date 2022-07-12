/*
*File : ch03/3.2/toupper.cpp
*Date : 2022-07-12
*Page : 83
*/

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string str = "Hello,World!";
    for (auto c: str){//此处的c只是临时变量，改变c不会对str造成影响
        c = toupper(c);
        cout << c;
    }
    cout << endl;
    cout << str << endl;

    for (auto &c: str){//此处的c是引用，改变c会改变str
        c = toupper(c);
        cout << c;
    }
    cout << endl;
    cout << str << endl;
    system("pause");
    return 0;
}