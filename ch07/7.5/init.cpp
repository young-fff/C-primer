/*
*File : ch06/7.5/init.cpp
*Date : 2022-07-21
*Page : 258
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ConstRef {
    public:
        ConstRef(int ii);
    private:
        int i;
        const int ci;
        int &ri;
};
ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }

/*
ConstRef::ConstRef(int ii)
{
    i = ii;
    ci = ii;
    ri = i;
}
*/

class Y {
    int i;
    int j;
public:

//i在j前初始化
    //Y(int val) : j(val), i(j) { }
    Y(int val) : j(val), i(val) { }
};

struct X {
    X (int i, int j) : base(i), rem(base % j) { }
    //int rem, base;
    int base, rem;
};

int main()
{
    Y y(1);
    return 0;
}