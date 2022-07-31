/*
*File : ch10/10.2/write.cpp
*Date : 2022-07-31
*Page : 340
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

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5};
    fill(ivec.begin(), ivec.end(), 0);
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;

    fill(ivec.begin(), ivec.begin() + ivec.size()/2, 10);
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;

    fill_n(ivec.begin(), 4, 5); //使用fill_n要求容器中至少包含n个元素
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;

    vector<int> vec;
    auto it = back_inserter(vec);
    *it = 42;
    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    vector<int> vec2;
    fill_n(back_inserter(vec2), 10, 1);
    for (auto i : vec2)
        cout << i << " ";
    cout << endl;

    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)];
    auto ret = copy(begin(a1), end(a1), a2);//ret返回a2尾后迭代器
    for (auto i : a2)
        cout << i << " ";
    cout << endl;

    replace(begin(a1), end(a1), 0, 99);
    for (auto i : a1)
        cout << i << " ";
    cout << endl;

    vector<int> vec3;
    replace_copy(begin(a1), end(a1), back_inserter(vec3), 99, 100);
    for (auto i : a1)
        cout << i << " ";
    cout << endl;
    for (auto i : vec3)
        cout << i << " ";
    cout << endl;

    vector<string> strvec{"aa", "bb", "aa", "dd", "cc"};
    elimDups(strvec);
    for (auto i : strvec)
        cout << i << " ";
    cout << endl;

    //system("pause");
    return 0;
}