/*
*File : ch11/11.4/word_count.cpp
*Date : 2022-08-04
*Page : 394
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>


using namespace std;
using std::istringstream;


int main()
{
    unordered_map<string, int> word_count;
    string word;
    while (cin >> word) {
        ++word_count[word];
    }
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

    system("pause");
    return 0;
}