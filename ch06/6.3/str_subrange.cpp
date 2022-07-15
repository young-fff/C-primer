/*
*File : ch06/6.3/str_subrange.cpp
*Date : 2022-07-16
*Page : 200
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size())
        return str1 == str2;
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i]  != str2[i])
            return false;
    }
    return true;
}

int main()
{
    cout << str_subrange("abc","abcd") << endl;
    system("pause");
    return 0;
}