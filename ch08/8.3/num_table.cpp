/*
*File : ch08/8.3/num_table.cpp
*Date : 2022-07-24
*Page : 289
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct PersonInfo {
    string name;
    vector<string> number;
    ostream& print(ostream& os);
};

ostream& PersonInfo::print (ostream& os)
{
    os << name << "\t";
    for (auto i : number) {
        os << i << " ";
    }
    cout << endl;
    return os;
}

int main()
{
    string line, word;
    vector<PersonInfo> people;
    ifstream ifs("ch08/8.3/personInfo.txt");
    if(ifs) {
        while (getline(ifs, line)) {
            PersonInfo info;
            istringstream record(line);
            record >> info.name;
            while (record >> word) {
                info.number.push_back(word);
            }
            people.push_back(info);
        }
    } else {
        cout << "No data?!" << endl;
    }
    for (auto i : people) {
        i.print(cout);
    }
    system("pause");
    return 0;
}