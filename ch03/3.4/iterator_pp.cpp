/*
*File : ch03/3.5/iterator_pp.cpp
*Date : 2022-07-13
*Page : 96
*/

#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main()
{
    string s("some thing");

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    cout << s <<endl;

    vector<string> s1{"some thing"};
    for (auto it = s1.cbegin(); it != s1.cend() && !it->empty(); ++it)
        cout << *it << endl;
    system("pause");
    return 0;
}