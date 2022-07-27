/*
*File : ch09/9.3/Sequentisl.cpp
*Date : 2022-07-27
*Page : 305
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
    vector<string> svec;
    string word;
    while (cin >> word)
        svec.push_back(word);

    list<int> ilist;
    for (size_t ix = 0; ix != 4; ++ix)
        ilist.push_front(ix);
    for (auto i : ilist)
        cout << i << " ";

    vector<string> stvec;
    list<string> stlist;
    stlist.insert(stlist.begin(), "Hello");//等价于insert_front
    stvec.insert(stvec.begin(), "Hello");//vector不支持insert_front，插入到尾部以外的位置都可能很慢、
    
    stvec.insert(stvec.end(), 10, "Anna");
    vector<string> v = {"quasi", "simba", "frollo", "scar"};
    stlist.insert(stlist.begin(), v.end() - 2, v.end());
    stlist.insert(stlist.end(), {"these", "words", "will", "go", "at", "the", "end"});
    //stlist.insert(stlist.begin(), stlist.begin(), stlist.end());//运行时错误，不能指向与目的地址相同的容器

    list<string> lst;
    auto iter = lst.begin();
    while (cin >> word)
        iter = lst.insert(iter, word);//等价于调用push_front
    system("pause");
    return 0;
}