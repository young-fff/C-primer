/*
*File : ch05/5.5/break.cpp
*Date : 2022-07-15
*Page : 171
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1) {
        if (s1 == s2) {
            break;
        } else {
            s2 = s1;
        }
    }
    if (s1 == s2) {
            cout << s1 << endl;
    } 
    system("pause");
    return 0;
}