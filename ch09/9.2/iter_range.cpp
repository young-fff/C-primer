/*
*File : ch09/9.2/iter_range.cpp
*Date : 2022-07-25
*Page : 297
*/

#include <iostream>
#include <vector>

using namespace std;

bool found(vector<int>::iterator iter1, vector<int>::iterator iter2, int goal)
{
    while(iter1 != iter2) {
        if (*iter1 == goal) return true;
        ++iter1;
    }
    return (*iter1 == goal);
}

vector<int>::iterator found_iter(vector<int>::iterator iter1, vector<int>::iterator iter2, int goal)
{
    while(iter1 != iter2) {
        if (*iter1 == goal) return iter1;
        ++iter1;
    }
    if (*iter1 == goal)
        return iter1;
    else 
        return iter2;
}

int main()
{
    std::vector<int> ivec{1,2,3,4,5};
    auto begin = ivec.begin();
    auto end = ivec.end() - 1;
    if (found(begin, end, 5))
        cout << "yes" << endl;
    else 
        cout << "no" << endl;
    system("pause");
    return 0;
}