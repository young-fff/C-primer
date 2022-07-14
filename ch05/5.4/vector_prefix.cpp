/*
*File : ch05/5.4/vector_prefix.cpp
*Date : 2022-07-14
*Page : 168
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v1{0,1,1,2};
    vector<int> v2{0,1,1,2,3,5,8};
    auto beg1 = v1.begin(), beg2 = v2.begin();
    for ( ; beg1 != v1.end() && beg2 != v2.end() && *beg1 == *beg2; ++beg1, ++beg2)
        ;
    cout << (beg1 == v1.end() || beg2 == v2.end()) << endl;   
    system("pause");
    return 0;
}