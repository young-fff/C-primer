/*
*File : ch04/4.7/cond.cpp
*Date : 2022-07-14
*Page : 134
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int grade = 100;
    string finalgrade = (grade < 60) ? "fail" : "pass";
    cout << finalgrade << endl;

    finalgrade = (grade > 90) ? "high pass"
                : (grade < 60) ? "fail" : "pass";
    cout << finalgrade << endl;

    grade =70;
    finalgrade = (grade > 90) ? "high pass"
                : (grade < 60) ? "fail" 
                : (grade < 75) ? "low pass" : "pass";
    cout << finalgrade << endl;

    cout << ((grade < 60) ? "fail" : "pass") << "   ";
    cout << (grade < 60) ? "fail" : "pass";
    cout << endl;
    //cout << grade < 60 ? "fail" : "pass" << endl;

    vector<int> v{1,2,3,4,5,6,7};
    for (auto &i : v) 
        i = (i % 2 == 1) ? 2 * i : i;
    for (const auto &i : v) 
        cout << i << " " ;
    cout << endl;

    string s = "word";
    string p1 = s + ((s[s.size() - 1] == 's') ? " " : "s") ;
    cout << p1 << endl;
    system("pause");
    return 0;
}