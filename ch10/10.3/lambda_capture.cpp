/*
*File : ch10/10.3/lambda_capture.cpp
*Date : 2022-08-01
*Page : 350
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include "Sales_data.h"

using namespace std;
using namespace std::placeholders;

void fcn1()
{
    size_t v1 = 42;
    auto f = [v1] {return v1;};
    v1 = 0;
    auto j = f();
    cout << j << endl;
}

void fcn2()
{
    size_t v1 = 42;
    auto f2 = [&v1] {return v1;};
    v1 = 0;
    auto j = f2();
    cout << j << endl;
}

void fcn3()
{
    size_t v1 = 42;
    auto f = [v1] () mutable {return ++v1;};
    v1 = 0;
    auto j = f();
    cout << j << endl;
}

void fcn4()
{
    size_t v1 = 42;
    auto f2 = [&v1] {return ++v1;};
    v1 = 0;
    auto j = f2();
    cout << j << endl;
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

bool check_size2(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

bool check_size3(int sz, string &s)
{
    return s.size() < sz;
}

bool isSmall(const int a, const int b)
{
    return a < b;
}

ostream &sprint(ostream &os, const string &s, char c)
{
    return os << s << c;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    auto wc2 = stable_partition(words.begin(), words.end(), bind(check_size2, _1, sz));

    auto count = words.end() - wc2;
    cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz << " or longer" << endl;

    for_each(wc2, words.end(), 
        [](const string &s) {cout << s << " ";});
    cout << endl;
}

int main()
{
    fcn1();
    fcn2();
    fcn3();
    fcn4();
    vector<int> vec{1, 2, 3, -1, -2, -3};
    //transform(vec.begin(), vec.end(), vec.begin(), [](int i) {return i < 0 ? -i : i;});//单一return 语句
    transform(vec.begin(), vec.end(), vec.begin(), [](int i) -> int {if (i < 0) return -i; else return i;});//使用尾指返回类型
    for (auto i : vec)
        cout << i << " ";
    cout << endl;

//利用count_if计数有多少单词长度超过6
    vector<string> svec{"aaaaa", "bb", "ccccccc", "dddddddddd", "e"};
    int sz = 6;
    auto count = count_if(svec.begin(), svec.end(), [sz](const string &s) {return s.size() > sz;});
    cout << "count = " << count << endl;

//统计长度小于等于6的数量
    count = count_if(svec.begin(), svec.end(), bind(check_size2, _1, 6));
    cout << "count = " << count << endl;

//找出vector中第一个大于string长度的值
    string str = "ha";
    auto iter = find_if(vec.begin(), vec.end(), bind(check_size3, _1, str));
    cout << "it is " << *iter << endl;

//编写一个lambda递减变量值
    int ival = 3;
    auto dec = [&ival] () -> bool {
        if (ival != 0) {
            --ival;
            return false;
        } else 
            return true;
    };
    while (!dec())
        cout << ival << " ";
    cout << endl;

//使用标准库bind函数绑定check_size的sz参数
    auto check6 = bind(check_size, placeholders::_1, 6);
    string s = "hello";
    bool b1 = check6(s);
    cout << "b1 = " << b1 << endl;
    auto wc = find_if(svec.begin(), svec.end(), bind(check_size, placeholders::_1, 6));
    auto cc = count_if(svec.begin(), svec.end(), bind(check_size, placeholders::_1, 6));
    cout << "count = " << count << endl;

//利用bind重排参数顺序
    vector<int> ivec{1, 2, 3, -1, -2, -3};
    sort(ivec.begin(), ivec.end(), isSmall);
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;

    vector<int> ivec2{1, 2, 3, -1, -2, -3};
    sort(ivec2.begin(), ivec2.end(), bind(isSmall, _2, _1));
    for (auto i : ivec2)
        cout << i << " ";
    cout << endl;

//利用标准库ref函数来用bind代替对ostream的捕获
    ostream &os = cout;
    char c = ' ';
    for_each(svec.begin(), svec.end(), [&os, c](const string &s) {os << s <<c;});
    cout << endl;
    for_each(svec.begin(), svec.end(), bind(sprint, ref(os), _1, ' '));
    cout << endl;

    biggies(svec, 6);
    system("pause");
    return 0;
}