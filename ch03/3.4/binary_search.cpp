/*
*File : ch03/3.5/binary_search.cpp
*Date : 2022-07-13
*Page : 100
*/

#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main()
{
    string text("abcdefghi");
    char sought;
    cin >> sought;
    auto beg = text.begin(), end = text.end();
    //cout << *beg <<endl;
    auto mid = text.begin() + (end - beg) / 2;
    while (mid != end && *mid != sought){
        if (sought < *mid)
            end = mid;
        else    
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    cout << *mid <<endl;
    system("pause");
    return 0;
}