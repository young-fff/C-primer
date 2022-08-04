/*
*File : ch11/11.2/multimap.cpp
*Date : 2022-08-04
*Page : 377
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main()
{
    map<string, vector<string>> family;
    family["Smith"] = {"Bob", "Alice"};
    family["Alon"] = {"Jack", "Musk"};
    family["Alon"].push_back("Erik");
    string birthday = "Today";
    vector<pair<string, string>> birth;
    for (auto &f : family) {
        cout << f.first << " : ";
        for (auto i : f.second) {
            cout << i << "  ";    
            birth.push_back(make_pair(i, birthday));
            birth.push_back({i, birthday});
            birth.push_back(pair<string, string> (i, birthday));
        }
        cout << endl;
    }
    system("pause");
    return 0;
}