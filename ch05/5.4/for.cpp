/*
*File : ch05/5.4/for.cpp
*Date : 2022-07-14
*Page : 166
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s{"hello world!"};
    for (decltype(s.size()) index = 0; 
        index != index && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]);

    vector<int> v{1,2,3,4};
    for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
        v.push_back(v[i]);

    auto beg = v.begin();
    for ( /*空语句*/; beg != v.end() && *beg >= 0; ++beg)
        ;
    for (int i = 0; /*条件为空*/ ; ++i){
        //循环内部必须负责终止迭代过程
    }

    for (int i; cin >> i; /*表达式为空*/)
        v.push_back(i);

    
    system("pause");
    return 0;
}