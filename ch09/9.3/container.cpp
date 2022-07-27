/*
*File : ch09/9.3/container.cpp
*Date : 2022-07-27
*Page : 309
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
    deque<string> sdeq;
    string word;
    list<string> slist;
    while (cin >> word) {
        sdeq.push_back(word);
        slist.push_back(word);
    }
    auto beg = sdeq.begin();
    while (beg != sdeq.end())
        cout << *beg++ << " ";
    cout << endl;

    auto lbeg = slist.begin();
    while (lbeg != slist.end()) 
        cout << *lbeg++ << " ";
    
    list<int> ilist{1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> ideq1;
    deque<int> ideq2;
    for (auto i : ilist) {
        if (i % 2)
            ideq1.push_back(i);
        else
            ideq2.push_back(i);
    }

    vector<string> lst;
    auto iter = lst.begin();
    while (cin >> word)
        iter = lst.insert(iter, word);
    system("pause");
    return 0;
}