/*
*File : ch10/10.3/lambda_test.cpp
*Date : 2022-07-31
*Page : 349
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <numeric>
#include <iterator>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    stable_sort(words.begin(), words.end(), 
        [](const string &a, const string &b) 
            {return a.size() < b.size();});
/*
    auto wc = partition(words.begin(), words.end(),
        [sz](const string &a) 
            {return a.size() < sz;});
*/
    auto wc2 = stable_partition(words.begin(), words.end(),
        [sz](const string &a) 
            {return a.size() < sz;});

    auto count = words.end() - wc2;
    cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz << " or longer" << endl;

    for_each(wc2, words.end(), 
        [](const string &s) {cout << s << " ";});
    cout << endl;
}

int main()
{
    auto f = [](int a, int b) {return a + b;};
    cout << f(1, 2) << endl;

    int val = 99;
    auto f2 = [val](int a) {return a + val;};
    cout << f2(1) << endl;

    vector<string> strvec{"bbb", "aaa", "aaa", "dddddddd", "ccc", "ddd", "dd", "bb", "eeeeee", "ffffff"};
    biggies(strvec, 3);
    system("pause");
    return 0;
}