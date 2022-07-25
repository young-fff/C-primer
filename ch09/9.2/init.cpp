/*
*File : ch09/9.2/init.cpp
*Date : 2022-07-25
*Page : 300
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;


int main()
{
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char*> articles = {"a", "an", "the"};

    list<string> list2(authors);
    //deque<string> authList(authors);
    //vector<string> words(articles);
    //deque<string> authList(authors.begin(), it);

    forward_list<string> words(articles.begin(), articles.end());
    system("pause");
    return 0;
}