/*
*File : ch09/9.3/iter.cpp
*Date : 2022-07-27
*Page : 316
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <array>

using namespace std;

int main()
{
    vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            iter += 2;
        } else {
            iter = vi .erase(iter);
        }
    }

    list<int> li{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter2 = li.begin();
    while (iter2 != li.end()) {
        if (*iter2 % 2) {
            iter2 = li.insert(iter2, *iter2);
            advance(iter2, 2);;
        } else {
            iter2 = li .erase(iter2);
        }
    }

    forward_list<int> fi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter3 = fi.begin();
    auto prev = fi.before_begin();
    while (iter3 != fi.end()) {
        if (*iter3 % 2) {
            iter3 = fi.insert_after(prev, *iter3);
            advance(iter3, 2);
            advance(prev, 2);
        } else {
            iter3 = fi.erase_after(prev);
        }
    }

    for (auto i : fi)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}