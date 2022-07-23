/*
*File : ch08/8.3/read_stream.cpp
*Date : 2022-07-24
*Page : 289
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream ifs;

int main()
{
    string line, word;
    vector<string> svec;
    if(ifs) {
        while (getline(ifs, line)) {
            svec.push_back(line);
        }
        for (auto i : svec) {
            istringstream record(i);
            while (record >> word) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}