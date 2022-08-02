/*
*File : ch10/10.4/insert_iter.cpp
*Date : 2022-08-02
*Page : 358
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <list>


using namespace std;

int main()
{
    list<int> lst = {1, 2, 3, 4};
    list<int> lst2, lst3;
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    for (auto i : lst2)
        cout << i << " ";
    cout << endl;
    for (auto i : lst3)
        cout << i << " ";
    cout << endl;

    vector<int> vec{1, 1, 1, 2, 2, 3, 4, 5};
    list<int> ilist(10);// 注意ilist要分配空间，否则没有地方拷贝，程序core掉。
    unique_copy(vec.begin(), vec.end(), ilist.begin());
    //ilist.resize(ilist.begin(), iter);
    for (auto i : ilist)
        cout << i << " ";
    cout << endl;

    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec2;
    vector<int> ivec3;
    list<int> ilist4;// 注意vector没有push_front方法，因此不能用front_inserter.  list有该方法
    copy(ivec.begin(), ivec.end(), inserter(ivec2, ivec2.begin()));
    copy(ivec.begin(), ivec.end(), back_inserter(ivec3));
    copy(ivec.begin(), ivec.end(), front_inserter(ilist4));
    for (auto i : ivec2)
        cout << i << " ";
    cout << endl;
    for (auto i : ivec3)
        cout << i << " ";
    cout << endl;
    for (auto i : ilist4)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}