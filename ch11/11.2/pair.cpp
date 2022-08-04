/*
*File : ch11/11.2/pair.cpp
*Date : 2022-08-04
*Page : 380
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <list>

using namespace std;

pair<string, int> process(vector<string> &v) 
{
    if (!v.empty()) 
        return {v.back(), v.back().size()}; //  列表初始化, C++11
        //return pair<string, int> (v.back(), v.back().size()); // 显示构造
        //return make_pair(v.back(), v.back().size());//make_pair // 自动判断参数类型
    else
        return pair<string, int>(); 
}

int main()
{
    pair<string, string> anon;
    pair<string, size_t> word_count;
    pair<string, vector<int> > line;

    vector<pair<string, int> > pvec;
    string str;
    int ival;
    pvec.push_back({str, ival});
    pvec.push_back(pair<string, int> (str, ival));
    pvec.push_back(make_pair(str, ival));

    system("pause");
    return 0;
}