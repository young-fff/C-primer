/*
*File : ch11/11.1/set.cpp
*Date : 2022-08-03
*Page : 374
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;
using std::remove_if;

bool myispunct(char &c)
{
    if (ispunct(c))
        return true;
    return false;
}

void test1103()
{
    map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        for (auto& ch : word) ch = tolower(ch);
        auto iter = remove_if(word.begin(), word.end(), myispunct);
        word.erase(iter, word.end());
        ++ word_count[word];
    }

    for (const auto& w : word_count) {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ?  " times" : " time.")  << endl;
    }
}

int main()
{
    map<string,size_t> word_cout;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};

    string word;
    while (cin >> word) {
        if (exclude.find(word) == exclude.end())
            ++word_cout[word];
    }
    for (const auto& w : word_cout)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    
    
    return 0;
}