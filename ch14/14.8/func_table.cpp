/*
*File : ch14/14.8/func_table.cpp
*Date : 2022-08-14
*Page : 511
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
using std::placeholders::_1;

int add(int i, int j) {return i + j;}

struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main()
{
    auto mod = [](int i, int j){return i % j;};

    map<string, int(*)(int, int)> binops;
    binops.insert({"+", add});
    //binops.insert({"%", mod}); //mod不是一个函数指针

    function<int(int, int)> f1 = add;
    function<int(int, int)> f2 = divide();
    function<int(int, int)> f3 = [](int i, int j){return i * j;};

    cout << f1(4, 2) << endl;
    cout << f2(4, 2) << endl;
    cout << f3(4, 2) << endl;

    map<string, function<int(int, int)>> binop = {
        {"+", add},
        {"-", minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j){return i * j;}},
        {"%", mod}
    };

    binop["+"](10, 5);
    binop["-"](10, 5);
    binop["/"](10, 5);
    binop["*"](10, 5);
    binop["%"](10, 5);

    int(*fp)(int, int) = add;   // 用指针消除二义性
    binop.insert({"+", fp});

    system("pause");
    return 0;
}