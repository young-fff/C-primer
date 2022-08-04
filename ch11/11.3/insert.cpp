/*
*File : ch11/11.3/operator.cpp
*Date : 2022-08-04
*Page : 382
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <list>

using namespace std;

void name()
{
    multimap<string, string> family;
    string family_name;
    vector<string> child_name;
    string name;
    int if_continue = 1;
    while (if_continue) {
        cout << "Please input the family name: ";
        cin >> family_name;
        cout << "Please input the child name: ";
        cin >> name;
        family.insert({family_name, name});
        cout << "Continue?(1/0)";
        cin >> if_continue;
    }

    for (const auto& f : family) {
        cout << f.first << "\t" << f.second << endl;
    }
}

int main()
{
    vector<int> ivec = {2, 4, 6, 8, 2, 4, 6, 8};
    set<int> set2;
    set2.insert(ivec.cbegin(), ivec.cend());
    cout << "the size of set2 : " << set2.size() << endl;
    set2.insert({1, 3, 5, 7, 1, 3, 5, 7});
    cout << "the size of set2 : " << set2.size() << endl;

    map<string,size_t> word_count;
    string word;
    word_count.insert({word, 1});
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));

//检测insert的返回值
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        auto ret = word_count.insert({word, 1});
        //pair<map<string, size_t>::iterator, bool> ret = word_count.insert({word, 1});
        if (!ret.second)
        //ret.first是一个map迭代器， map<string, size_t>::iterator
            ++ret.first -> second;//等价于++((ret.first) -> second);
    }

//向multiset和multimap中插入元素
    multimap<string, string> authors;
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});
//只返回只相新插入元素的迭代器，不返回bool值因为插入往往成功

    system("pause");
    return 0;
}