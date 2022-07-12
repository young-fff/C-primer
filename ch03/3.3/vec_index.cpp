/*
*File : ch03/3.2/vec_index.cpp
*Date : 2022-07-13
*Page : 93
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade){
        ++scores[grade/10];
    }
    for (auto i : scores)
        cout << i <<" ";
    cout << endl;
    system("pause");
    return 0;
}