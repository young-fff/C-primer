/*
*File : ch04/4.6/mem_visit.cpp
*Date : 2022-07-14
*Page : 134
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> v{"1","2","3","4"};
    auto iter = v.begin();
    cout << *iter++ << endl;
    //cout << (*iter)++ << endl;
    //cout << *iter.empty() << endl;
    cout << iter->empty() << endl;
    //cout << ++*iter << endl;
    cout << iter++->empty() << endl;

    system("pause");
    return 0;
}