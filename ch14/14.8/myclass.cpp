/*
*File : ch14/14.8/myclass.cpp
*Date : 2022-08-13
*Page : 506
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Myclass {
public:
    Myclass (int n) : num(n) {}
    int operator() (int x, int y, int z);
private:
    int num;
};

int Myclass::operator()(int x, int y, int z) 
{
    return (x == num) ? y : z;
}

class  isequal
{
private:
    int val;
public:
    isequal(int n) : val(n) {}
    bool operator()(int num) 
    {
        return val == num;
    }
};



int main()
{
    Myclass mc(10);
    int x = mc(9, 5, 20);
    cout << x << endl;

    vector<int> ivec{1, 2, 3, 4, 5};
    replace_if(ivec.begin(), ivec.end(), isequal(2), 10);
    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}