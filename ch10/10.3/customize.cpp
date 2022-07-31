/*
*File : ch10/10.3/customize.cpp
*Date : 2022-07-31
*Page : 344
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <numeric>
#include <iterator>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> strvec{"bbb", "aaa", "aaa", "dddd", "ccc", "ddd", "dd", "bb"};
    elimDups(strvec);
    for (auto i : strvec)
        cout << i << " ";
    cout << endl;
    //sort(strvec.begin(), strvec.end(), isShorter);
    stable_sort(strvec.begin(), strvec.end(), isShorter);
    for (auto i : strvec)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}