/*
*File : ch12/12.2/connect_char.cpp
*Date : 2022-08-07
*Page : 426
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>
#include <string.h>


using namespace std;

char* connected_char(const char* str1, const char* str2)
{
    char* res = new char[strlen(str1) + strlen(str2)];
    int i = 0;
    for (; i < strlen(str1); i++)
        res[i] = str1[i];
    for (int j = 0; j < strlen(str2); j++)
        res[i + j] = str2[j];
    return res;
}

string connected_string(const string& str1, const string& str2)
{
    string str = str1 + str2;
    return str;
}

void test()
{
    string str;
    cin >> str;
    char* c_array = new char[str.size()];
    for (int i = 0; i < str.size(); i++)
        c_array[i] = str[i];
    cout << c_array << endl;
    delete [] c_array;
}

int main()
{
    auto res = connected_char("Hello", "World");
    for (int i = 0; i < strlen(res); i++)
        cout << res[i];
    cout << endl;

    string s1 = "Hello", s2 = "World";
    auto res2 = connected_string(s1, s2);
    cout << res2 << endl;

    test();
    system("pause");
    return 0;
}