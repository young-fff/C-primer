/*
*File : ch06/6.5/read_vec.cpp
*Date : 2022-07-16
*Page : 217
*/

#include <iostream>
#include <string>
#include <vector>
//#define NDEBUG
using namespace std;

void read_vec(vector<int>::iterator iter,vector<int>::iterator end)
{
    cout << *iter << endl;
    #ifndef NDEBUG
        cerr << "Size is " << end - iter + 1 << endl;
    #endif
    if (iter != end)
        read_vec(++iter, end);
}

int main()
{
    vector<int> v{1,2,3,4,5};
    read_vec(v.begin(),v.end()-1);
    system("pause");
    return 0;
}