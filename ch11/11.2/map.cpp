/*
*File : ch11/11.2/map.cpp
*Date : 2022-08-04
*Page : 379
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
    map<string, list<size_t> > mmap;

//可以编译通过，不能实际使用，因为iterator不支持比较操作
    map<vector<int>::iterator, int> imap;
    map<list<int>::iterator, int> lmap;

    system("pause");
    return 0;
}