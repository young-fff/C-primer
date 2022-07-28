/*
*File : ch09/9.5/str_find.cpp
*Date : 2022-07-28
*Page : 326
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <array>

using namespace std;

void find_longest(string& str)
{
    //string str = "aacgaesse";
    string alpha = "aceimnorsuvwxz";
    int pos1 = 0, pos2 = 0, pos3 = 0, max_len = 0;
    string res;

    for (;(pos1 = str.find_first_of(alpha, pos1)) != string::npos; ++pos1) {
        pos2 = pos1;
        if ((pos2 = str.find_first_not_of(alpha, pos2)) != string::npos) {
            if ((pos2 - pos1) > max_len) {
                max_len = pos2 - pos1;
                pos3 = pos1;
                pos1 = pos2;
            }
        } else {
            if (max_len < (str.size() - pos1)) {
                max_len = str.size() - pos1;
                pos3 = pos1;
                break;
            }
        }
    }
    cout << str.substr(pos3, max_len) << endl;
}

int main()
{
    string numbers("0123456789"), name("ab2c3d7R4E6");
    string::size_type pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos << " element is " << name[pos] << endl;
        ++pos;
    }
    cout << endl;
    pos = 0;
    while ((pos = name.find_first_not_of(numbers, pos)) != string::npos) {
        cout << "found letter at index: " << pos << " element is " << name[pos] << endl;
        ++pos;
    }

    string st{"aacgaesse"};
    find_longest(st);

    system("pause");
    return 0;
}