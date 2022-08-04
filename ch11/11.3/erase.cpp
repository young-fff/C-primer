/*
*File : ch11/11.3/erase.cpp
*Date : 2022-08-04
*Page : 386
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
    string removal_word;
    word_count.insert({"Hello", 1});
    removal_word = "Hello";
    if (word_count.erase(removal_word))
        cout << "ok: " << removal_word << " removed\n";
    else cout << "oops: " << removal_word << " not found!\n";

    multimap<string, string> authors;
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    string search_item("Barth, John");//待查找的作者
    auto iter = authors.find(search_item);//查找的作者的第一本书
    if (iter != authors.end())
        authors.erase(iter);

    multimap<string, string> auth_map = {
        {"John", "computer"},
        {"Joe", "science"},
        {"John", "art"},
        {"Angle", "design"}
    };
    map<string, set<string>> ssmap;
    for (auto &author : auth_map) {
        ssmap[author.first].insert(author.second);
    }
    for (const auto& auth : ssmap) {
        cout << auth.first << " : ";
        for (const auto& book : auth.second) {
            cout << book << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}