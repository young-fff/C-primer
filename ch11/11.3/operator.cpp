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

int main()
{
    map<string,size_t> word_count;
    string word;
    while (cin >> word) {
        ++word_count[word];
    }
    for (const auto& w : word_count)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? "times" : "time") << endl;

    auto map_it = word_count.begin();
    cout << map_it -> first << " " << map_it -> second;
    //map_it -> first = "new key"; //value_type的first成员为const类型
    ++map_it -> second;//second成员不是const，可以用迭代器改变


    set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<int>::iterator set_it = iset.begin();
    if (set_it != iset.end()) {
        //*set_it = 42; //错误：set的关键字是只读的
        cout << *set_it << endl;
    }

//遍历关联容器
    auto map_it = word_count.cbegin();
    while (map_it != word_count.cend()) {
        cout << map_it -> first << " occurs " << map_it -> second << " times " << endl;
        ++map_it;
    }

    map<string, size_t>::const_iterator map_it = word_count.cbegin();
    while (map_it != word_count.cend()) {
        cout << map_it -> first << " occurs " << map_it -> second << " times " << endl;
        ++map_it;
    }

    map<string, int> word_no;
    map<string, int>::iterator iter = word_no.begin();
    iter -> second = 1;

    vector<string> v;
    multiset<string> c;
    copy(v.begin(), v.end(), inserter(c, c.end()));	
// 将v中的元素拷贝到c中。使用合法，可以使用inserter将关联容器当作一个目的位置。
    copy(v.begin(), v.end(), back_inserter(c));
// 意义同上，但是不合法，因为multiset没有push_back方法，不能调用back_inserter
    copy(c.begin(), c.end(), inserter(v, v.end()));
// 将c中的元素拷贝到v中，使用合法，vector可以使用inserter。
    copy(c.begin(), c.end(), back_inserter(v));
// 意义同上，合法，vector有push_back方法，可以使用back_inserter.

    system("pause");
    return 0;
}