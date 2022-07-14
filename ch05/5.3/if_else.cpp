/*
*File : ch05/5.3/if_else.cpp
*Date : 2022-07-14
*Page : 157
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    const vector<string> scores{"F","D","C","B","A","A++"};
    
    int grade;
    cin >> grade;
    string lettergrade;
    if (grade < 60)
        lettergrade = scores[0];
    else
        lettergrade = scores[(grade - 50) / 10];
    cout << lettergrade <<endl;

    if (grade % 10 > 7)
        lettergrade += '+';
    else if (grade % 10 < 3)
        lettergrade += '-';
    cout << lettergrade <<endl;

    if (grade < 60)
        lettergrade = scores[0];
    else {
        lettergrade = scores[(grade - 50) / 10];
        if (grade != 100)
            if (grade % 10 > 7)
                lettergrade += '+';
            else if (grade % 10 < 3)
                lettergrade += '-';
    }
    cout << lettergrade <<endl;

    lettergrade = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];
    lettergrade += (grade == 100) ? ' '
        : (grade % 10 > 7) ? '+' 
            : (grade % 10 < 3) ? '-' : ' ';
    cout << lettergrade <<endl;
/*
    int ival1, ival2 = 1;
    if (ival1 != ival2)
        ival1 = ival2;
    else ival1 = ival2 = 0;
    cout << ival1 << ival2 << endl;
*/
    system("pause");
    return 0;
}