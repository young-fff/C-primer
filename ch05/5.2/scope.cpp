/*
*File : ch05/5.2/scope.cpp
*Date : 2022-07-14
*Page : 155
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v{1,2,3,4};
    
    auto beg = v.begin();
    while (beg != v.end() && *beg >= 0)
        ++beg;
    if (beg == v.end())
        ;
    string s = "abc";
    string::iterator iter;
    while (iter != s.end()) { //每次迭代都重新初始化
        ;
    }
/*
    while (bool status = find(word)) {
        ;
    }
    if (!status) {
        ;
    }
*///不能再循环外部访问status
    system("pause");
    return 0;
}