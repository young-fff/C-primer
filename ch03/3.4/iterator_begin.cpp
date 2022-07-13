/*
*File : ch03/3.5/iterator_begin.cpp
*Date : 2022-07-13
*Page : 95
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("some thing");

    if (s.begin() != s.end()){
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s <<endl;
    system("pause");
    return 0;
}