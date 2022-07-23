/*
*File : ch08/8.1/readIS.cpp
*Date : 2022-07-22
*Page : 281
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

istream& readIS(istream& is) 
{
    string word;
    while (is >> word) {
        cout << word << " ";
    }
    cout << endl;
    is.clear();
    return is;
}

void test()
{
    readIS(cin);
}

int main()
{
    test();
    system("pause");
    return 0;
}