/*
*File : ch08/8.2/buf.cpp
*Date : 2022-07-22
*Page : 284
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sales_data.h"

using namespace std;

void readFile(const string& fileName, vector<string>& svec)
{
    ifstream ifs(fileName);
    if (ifs) {
        string buf;
        while(getline(ifs, buf)) {
            svec.push_back(buf);
        }
    }
}

void readFileByWord(const string& fileName, vector<string>& svec)
{
    ifstream ifs(fileName);
    if (ifs) {
        string buf;
        while(ifs >> buf) {
            svec.push_back(buf);
        }
    }
}

int main()
{
    string filename = "ch08/8.2/file_test.txt";
    vector<string> vec;
    readFileByWord(filename, vec);
    ofstream ofs;
    for (auto i : vec) {
        cout << i << endl;
    }

    system("pause");
    return 0;
}