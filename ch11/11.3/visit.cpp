/*
*File : ch11/11.3/visit.cpp
*Date : 2022-08-04
*Page : 388
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
    set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter1 = iset.find(1);
    auto iter2 = iset.find(11);
    int i = iset.count(1);
    int i2 = iset.count(11);
    cout << "i= " << i << "  i2= " << i2 << endl;

    map<string,size_t> word_count;
    string word;
    word_count.insert({"Hello", 1});
    if (word_count.find("foobar") == word_count.end())
        cout << "foobar is not in the map" << endl;

//使用find和count来查找
    multimap<string, string> authors;
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    string search_item("Barth, John");//待查找的作者
    auto iter = authors.find(search_item);//查找的作者的第一本书
    auto entries = authors.count(search_item);//数量
    while (entries) {
        cout << iter -> second << endl; //打印
        ++iter; //到下一本
        --entries; //倒数
    } 

//使用lower_bound和upper_bound来查找
    for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg)
        cout << beg -> second << endl;

//使用equal_range函数查找
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
        cout << pos.first -> second << endl;

    map<string, int> simap;
    map<string, int>::iterator it = simap.find("str");

    system("pause");
    return 0;
}