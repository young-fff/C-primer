/*
*File : ch14/14.8/length.cpp
*Date : 2022-08-14
*Page : 508
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class StrLen {
public:
    StrLen(size_t n) : sz(n) {}
    bool operator()(const string &s) {return s.size() == sz;}
    size_t getSize() {return sz;}
private:
    size_t sz;
};

int main()
{
    vector<StrLen> pred;
    map<size_t, size_t> len_cnt_table;

    for (size_t i = 1; i < 11; ++i) {
        len_cnt_table[i] = 0;
        pred.push_back(StrLen(i));
    }
    string word;
    while (cin >> word) {
        for (auto i : pred) {
            if (i(word)) {
                ++ len_cnt_table[i.getSize()];
            }
        }
    }

    for (auto i : len_cnt_table) {
        cout << i.first << " " << i.second << endl;
    }

    system("pause");
    return 0;
}