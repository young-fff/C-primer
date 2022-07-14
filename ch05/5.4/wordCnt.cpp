/*
*File : ch05/5.4/wordCnt.cpp
*Date : 2022-07-14
*Page : 166
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> v;
    string i;
    while (cin >> i)
        v.push_back(i);
    auto beg = v.begin();
    auto next = beg + 1;
    int same_t = 1, max_t = 1;
    string max_same;
    while (next != v.end()) {
        if (*beg == *next) {
            ++same_t;
        } else {
            same_t = 1;
        }
        if (same_t > max_t) {
            max_t = same_t;
            max_same = *beg;
        }
        ++beg;
        ++next;
    }
    cout << "max_word : " << max_same <<"   times : " << max_t <<endl;
    system("pause");
    return 0;
}