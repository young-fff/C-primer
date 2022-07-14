/*
*File : ch04/4.8/bit_compute.cpp
*Date : 2022-07-14
*Page : 135
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    unsigned char bits = 0233;  //表示8进制的233
    cout << bits << endl;

    auto bits2 = bits << 8;
    cout << bits2 << endl;

    auto bits3 = bits << 31;
    cout << bits3 << endl;

    auto bits4 = bits >> 3;
    cout << bits4 << endl;

    bits = 0227;
    cout << bits << endl;

    auto bits5 = ~bits;
    cout << bits5 <<endl;

    unsigned long quiz1 = 0;
    1UL << 27;
    quiz1 |= 1UL << 27;     
    //等价于quiz1 = quiz1 | 1UL << 27

    quiz1 &= ~(1UL << 27);

    bool status = quiz1 & (1UL << 27);

    unsigned long ul1 = 3, ul2 = 7;
    cout << (ul1 & ul2) << endl;
    cout << (ul1 | ul2) << endl;
    cout << (ul1 && ul2) << endl;
    cout << (ul1 || ul2) << endl;
    system("pause");
    return 0;
}