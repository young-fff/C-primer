/*
*File : ch04/4.2/div.cpp
*Date : 2022-07-14
*Page : 125
*/

#include <iostream>
using namespace std;

int main()
{
    bool i = true;
    bool i2 = -i;
    cout << i2 << endl;

    int ival1 = 21/6;
    int ival2 = 21/7;
    cout << ival1 << " " << ival2 << endl;

    int ival = 42;
    double dval = 3.14;
    ival % 13;
    //ival % dval;

    cout << "21 % 6 = " << 21 % 6 << " " << "21 / 6 = " << 21 / 6 << endl;
    cout << "21 % 7 = " << 21 % 7 << " " <<"21 / 7 = " << 21 / 7 << endl;
    cout << "-21 % -8 = " << -21 % -8 << " " <<"-21 / -8 = " << -21 / -8 << endl;
    cout << "21 % -5 = " << 21 % -5 << " " <<"21 / -5 = " << 21 / -5 << endl;

    cout << "12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 = " << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;

    system("pause");
    return 0;
}