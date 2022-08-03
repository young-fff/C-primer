/*
*File : ch11/11.1/map.cpp
*Date : 2022-08-03
*Page : 374
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string,size_t> word_cout;
    string word;
    while (cin >> word) {
        ++word_cout[word];
    }
    for (const auto& w : word_cout)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? "times" : "time") << endl;

    system("pause");
    return 0;
}