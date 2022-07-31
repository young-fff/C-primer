/*
*File : ch10/10.2/only_read.cpp
*Date : 2022-07-31
*Page : 338
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5};
    auto result = accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << "The sum of ivec is " << result << endl;

    vector<string> svec{"hello", " ", "world", "!"};
    //auto res2 = accumulate(svec.cbegin(), svec.cend(), ""); const char*没有+操作
    auto res = accumulate(svec.cbegin(), svec.cend(), string(""));
    cout << "The sum of svec is " << res << endl;

    vector<int> ivec1{1, 2, 3, 4, 5};
    vector<int> ivec2{1, 2, 2, 4, 5};
    auto isequal = equal(ivec1.cbegin(), ivec1.cend(), ivec2.cbegin());
    cout << "ivec1 is" << (isequal ? " " : " not ") << "equal to ivec2" << endl; 
    system("pause");
    return 0;
}