/*
*File : ch05/5.4/while.cpp
*Date : 2022-07-14
*Page : 169
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string rsp;
    do {
        cout << "please enter two value: ";
        int val1 = 0, val2 = 0;
        cin >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
            << " = " << val1 + val2 << "\n\n"
            << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');

    do {
        cout << "please enter two string: ";
        string s1, s2;
        cin >> s1 >> s2;
        cout << "The shorter one between " << s1 <<" and " << s2 
        << " is " << ((s1 < s2) ? s1 : s2) << "\n\n"
            << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
    
    system("pause");
    return 0;
}