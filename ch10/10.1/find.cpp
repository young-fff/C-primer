/*
*File : ch10/10.1/find.cpp
*Date : 2022-07-31
*Page : 336
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

int main()
{
    vector<int> vec{0,1,42,0};
    int val = 42;
    auto result = find(vec.cbegin(), vec.cend(), val);
    cout << "The value " << val << (result == vec.cend() ? " is not present" : " is present") << endl;

    list<string> lst;
    string str = "a value";
    auto result1 = find(lst.cbegin(), lst.cend(), str);
    cout << "The string " << str << (result1 == lst.cend() ? " is not present" : " is present") << endl;

    int ia[] = {27, 210, 12, 47, 109, 83};
    int val2 = 83;
    int* result2 = find(begin(ia), end(ia), val2);
    cout << "The val " << val2 << (result2 == end(ia) ? " is not present" : " is present") << endl;

    auto result3 = find(ia + 1, ia + 4, val2);
    cout << "The val " << val2 << (result3 == ia + 4 ? " is not present" : " is present") << endl;
/*
    int val3 = 1;
    vector<int> ivec;
    int i;
    while (cin >> i) {
        ivec.push_back(i);
    }
    
    auto res = count(ivec.cbegin(), ivec.cend(), val3);
    cout << val3 << " has present " << res << " time in ivec" << endl;
*/
    string str2 = "1";
    list<string> slst;
    string sl;
    while (cin >> sl) {
        slst.push_back(sl);
    }
    auto res2 = count(slst.cbegin(), slst.cend(), str2);
    cout << str2 << " has present " << res2 << " time in slst" << endl;
    system("pause");
    return 0;
}