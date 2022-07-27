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

    vector<int> v1; //  空
    vector<int> v2{1,2,3,4,5};  //1,2,3,4,5
    vector<int> v3 = {6, 7, 8, 9, 10};  //6,7,8,9,10
    vector<int> v4(v2); //1,2,3,4,5
    vector<int> v5 = v3;    //6,7,8,9,10
    vector<int> v6(10, 4); //10个4

    list<int> lis;
    vector<double> dvec(lis.begin(), lis.end());
    vector<int> ivec;
    vector<double> dvec2(ivec.begin(), ivec.end());
    system("pause");
    return 0;
}