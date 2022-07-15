/*
*File : ch06/6.3/ret_list.cpp
*Date : 2022-07-16
*Page : 203
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> process()
{
    string expected{"apple"};
    string actual{"banana"};
    if (expected.empty())
        return {};
    else if (expected == actual)
        return {"functionX", "okay"};
    else
        return {"functionX", expected, actual};
}

int main()
{
    auto v = process();
    for (auto beg = v.begin(); beg != v.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
    system("pause");
    return 0;
}