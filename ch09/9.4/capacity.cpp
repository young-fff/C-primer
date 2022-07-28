/*
*File : ch09/9.4/capacity.cpp
*Date : 2022-07-28
*Page : 319
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <array>

using namespace std;

int main()
{
    vector<int> vi;
    cout << " vi:size : " << vi.size() << " capacity : " << vi.capacity() << endl;
    for (auto ix = 0; ix != 24; ++ix) {
        vi.push_back(ix);
    }
    cout << " vi:size : " << vi.size() << " capacity : " << vi.capacity() << endl;
    vi.reserve(50);
    cout << " vi:size : " << vi.size() << " capacity : " << vi.capacity() << endl;
    while (vi.size() != vi.capacity()) {
        vi.push_back(0);
    }
    cout << " vi:size : " << vi.size() << " capacity : " << vi.capacity() << endl;
    vi.push_back(42);
    cout << " vi:size : " << vi.size() << " capacity : " << vi.capacity() << endl;
    vi.shrink_to_fit();
    cout << " vi:size : " << vi.size() << " capacity : " << vi.capacity() << endl;

    vector<int> ivec;
    int value;
    while (cin >> value) {
        ivec.push_back(value);
        cout << " ivec:size : " << ivec.size() << " capacity : " << ivec.capacity() << endl;
    }
    

    system("pause");
    return 0;
}