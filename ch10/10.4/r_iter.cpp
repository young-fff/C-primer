/*
*File : ch10/10.4/r_iter.cpp
*Date : 2022-08-02
*Page : 358
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <list>
#include <string>

using namespace std;

int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter)
        cout << *r_iter << " ";
    cout << endl;
    sort(vec.begin(), vec.end());
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    sort(vec.rbegin(), vec.rend());
    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    string str = "one,two,three,four";
    auto comma = find(str.cbegin(), str.cend(), ',');
    cout << string(str.cbegin(), comma) << endl;

    auto rcomma = find(str.crbegin(), str.crend(), ',');
    cout << string(str.crbegin(), rcomma) << endl;//逆序输出单词的字符 ruof
    cout << string(rcomma.base(), str.cend()) << endl;//输出four

    list<int> lst{0, 1, 2, 3, 4, 0, 5};
    auto f_iter = find(lst.crbegin(), lst.crend(), 0);
    cout << distance(f_iter, lst.crend()) << endl;

    system("pause");
    return 0;
}