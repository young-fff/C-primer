/*
*File : ch10/10.3/lambda.cpp
*Date : 2022-07-31
*Page : 346
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
    //stable_sort(words.begin(), words.end(), isShorter);
    //如果想指定参数为划分大小的标准，谓词无法满足
    //按字典序排序，删除重复元素
    stable_sort(words.begin(), words.end(), 
        [](const string &a, const string &b) 
            {return a.size() < b.size();});
    //按长度排序，长度相同的维持字典序
    auto wc = find_if(words.begin(), words.end(),
        [sz](const string &a) 
            {return a.size() >= sz;});//如果不捕获sz，则发生错误
    //wc为一个迭代器，指向第一个满足size() >= sz 的元素
    auto count = words.end() - wc;
    //count为满足size() >= sz 的元素数量
    cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz << " or longer" << endl;

    for_each(wc, words.end(), 
        [](const string &s) {cout << s << " ";});
    //打印满足size() >= sz 的元素
    cout << endl;
}

int main()
{
    auto f = [] {return 42;};
    cout << f() << endl;
    vector<string> strvec{"bbb", "aaa", "aaa", "dddd", "ccc", "ddd", "dd", "bb", "eeeeee", "ffffff"};
    biggies(strvec, 4);
    system("pause");
    return 0;
}