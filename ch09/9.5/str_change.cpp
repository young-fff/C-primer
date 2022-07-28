/*
*File : ch09/9.5/str_change.cpp
*Date : 2022-07-28
*Page : 324
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <array>

using namespace std;

void str_change(string &s, string &oldVal, string &newVal)
{
    auto old_size = oldVal.size(); 
    auto iter_s = s.begin();
    for (;iter_s <= (s.end() - oldVal.size() + 1); ++iter_s) {
        if (s.substr((iter_s - s.begin()), old_size) == oldVal) {
            iter_s = s.erase(iter_s, iter_s + old_size);
            iter_s = s.insert(iter_s, newVal.begin(),newVal.end());
            advance(iter_s,newVal.size());
        }
    }
}

void str_change2(string &s, string &oldVal, string &newVal)
{
    auto old_size = oldVal.size(); 
    auto iter_s = s.begin();
    for (;iter_s <= (s.end() - oldVal.size() + 1); ++iter_s) {
        if (s.substr((iter_s - s.begin()), old_size) == oldVal) {
            s = s.replace(iter_s, iter_s + old_size, newVal);
            iter_s = s.begin();
        }
    }
}

string& addToName(string& name, const string& pre, const string& suf) 
{
    auto beg = name.begin();
    string result;
    beg = name.insert(beg, pre.begin(), pre.end());
    return name.append(suf);
}

string& addToName2(string& name, const string& pre, const string& suf) 
{
    auto beg = name.begin();
    string result;
    beg = name.insert(beg, pre.begin(), pre.end());
    name.insert(name.end(), suf.begin(), suf.end());
    return name;
}

int main()
{
    string str = "abc thru efg thru";
    string oldStr = "thru";
    string newStr = "through";
    str_change2(str, oldStr, newStr);
    cout << str << endl;
    string pre_name = "Wang";
    string after_name = addToName2(pre_name, "Miss.", " III");
    cout << after_name << endl;

    system("pause");
    return 0;
}