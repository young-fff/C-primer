/*
*File : ch03/3.2/getline.cpp
*Date : 2022-07-12
*Page : 78
*/

#include <iostream>
using namespace std;

int main()
{
    string word;
    int i = 0;
    while (getline(cin, word))
        cout << "Line" << ++i  << ": " << word << endl;

    while (getline(cin, word))
        if (!word.empty())
    cout << "Line" << ++i  << ": " << word << endl;

    while (getline(cin, word))
        if (word.size() > 80)
            cout << "Line" << ++i  << ": " << word << endl;
    system("pause");
    return 0;
}