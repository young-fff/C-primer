/*
*File : ch06/6.2/refer_par.cpp
*Date : 2022-07-15
*Page : 190
*/

#include <iostream>
#include <string>
using namespace std;

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;     //出现次数由occurs隐式返回
}
int main()
{
    string str = "hello world!";
    string::size_type ctr;
    auto index = find_char(str, 'o', ctr);
    cout << index << " " << ctr << endl;
    system("pause");
    return 0;
}