/*
*File : ch14/14.8/lambda.cpp
*Date : 2022-08-14
*Page : 508
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ShorterString {
public:
    bool operator() (const string &s1, const string &s2) const
        {return s1.size() < s2.size();}
};

class  SizeComp
{
private:
    size_t sz;
public:
     SizeComp(size_t n);
     bool operator() (const string &s) const
        {return s.size() >= sz;}
};

SizeComp:: SizeComp(size_t n) : sz(n) {}


int main()
{
    vector<int> words{0, 1, 2, 5, 4, 3};

   stable_sort(words.begin(), words.end(), 
    [](const string &a, const string &b){return a.size() < b.size();});

    stable_sort(words.begin(), words.end(), ShorterString());

    size_t sz;
    auto wc = find_if(words.begin(), words.end(), SizeComp(sz));

    system("pause");
    return 0;
}