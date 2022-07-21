/*
*File : ch06/7.4/test7_35.cpp
*Date : 2022-07-20
*Page : 258
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string Type;
Type initVal();
class Exercise {
    public:
        typedef double Type;
        Type setVal(Type);
        Type initVal();
    private:
        int val;
};
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}