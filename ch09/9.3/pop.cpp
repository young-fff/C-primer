/*
*File : ch09/9.3/pop.cpp
*Date : 2022-07-27
*Page : 312
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
    list<int> ilist{1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (!ilist.empty()) {
        ilist.pop_front();
    }

    list<int> lst{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = lst.begin();
    while (it != lst.begin())
        if (*it % 2)
            it = lst.erase(it);
        else
            ++it;
    
    int ia[] = {0, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> iav(begin(ia), end(ia));
    list<int> ial(begin(ia), end(ia));
    auto vbeg = iav.begin();
    auto lbeg = ial.begin();
    while (lbeg != ial.end()) {
        if (*lbeg % 2) {
            lbeg = ial.erase(lbeg);  
            ++vbeg;
        } else {
            vbeg = iav.erase(vbeg);
            ++lbeg;
        }
    }
    for (auto i : iav)
        cout << i << " ";
    cout << endl;
    for (auto i : ial)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}