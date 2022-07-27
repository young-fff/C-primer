/*
*File : ch09/9.3/forward_list.cpp
*Date : 2022-07-27
*Page : 313
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <array>

using namespace std;

void find_insert(forward_list<string> &sflt, string &goal, string &str)
{
    auto prev = sflt.before_begin();
    auto iter = sflt.begin();
    auto iend = sflt.end();
    while (iter != iend) {
        if (*iter == goal) {
            sflt.insert_after(iter, str);
            return;
        } else {
            prev = iter;
            ++iter;
        } 
    }
    sflt.insert_after(iter, str);
}
int main()
{
    forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) 
            curr = flst.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }
    for (auto i : flst)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}