/*
*File : ch06/6.2/string_par.cpp
*Date : 2022-07-15
*Page : 192
*/

#include <iostream>
#include <string>
using namespace std;

bool HasUpper(const string& str)
{
    auto beg = str.begin();
    while (beg != str.end())
    {
        if (isupper(*beg))
            return true;
        ++beg;
    }
    return false;
}

void Tolower(string &str)
{
    for (auto beg = str.begin(); beg != str.end(); ++beg)
        *beg = tolower(*beg);
}

int main()
{
    string str{"aBc"};
    bool r = HasUpper(str);
    Tolower(str);
    cout << r << " " << str << endl;
    system("pause");
    return 0;
}