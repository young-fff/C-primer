/*
*File : ch11/11.2/multiset.cpp
*Date : 2022-08-03
*Page : 377
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;

    vector<string> svec;
    //string word;
    vector<string> svec2{"aa", "sa", "as", "ad", "ad", "as"};
    for(auto word : svec2) {
        if (find(svec.cbegin(), svec.cend(), word) == svec.end()) {
            svec.push_back(word);
        }
    }
    for (auto i : svec) 
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}