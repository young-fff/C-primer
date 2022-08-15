/*
*File : ch14/14.9/conversion.cpp
*Date : 2022-08-15
*Page : 514
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
using std::placeholders::_1;

class SmallInt {
    //friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    //SmallInt(int i = 0);
    SmallInt(int i = 0) : val(i)
    {
        if (i < 0 || i > 255)
            throw out_of_range("Bad SmallInt value");
    }
    operator int() const {return val;}
private:
    size_t val;
};

class SmallInt2;
//operator int(SmallInt&);
class SmallInt2 {
public:
    //int operator int() const;
    //operator int(int = 0) const;
    //operator int*() const {return 42;}
};

class SmallInt3 {
public:
    explicit operator int() const {return val;}
    SmallInt3(int i = 0) : val(i)
        {
            if (i < 0 || i > 255)
                throw out_of_range("Bad SmallInt value");
        }
        operator int() const {return val;}
private:
    size_t val;
};

int main()
{
    SmallInt si;
    si = 4;
    si + 3;

    SmallInt sii = 3.14;
    si + 3.14; 

    SmallInt3 siii = 3;
    // si + 3;
    static_cast<int>(si) + 3;

    system("pause");
    return 0;
}