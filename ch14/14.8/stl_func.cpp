/*
*File : ch14/14.8/stl_func.cpp
*Date : 2022-08-14
*Page : 510
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
using std::placeholders::_1;


int main()
{
    plus<int> intAdd;
    negate<int> intNegate;
    int sum = intAdd(10, 20);
    sum = intNegate(intAdd(10, 20));
    sum = intAdd(10, intNegate(10));

    vector<string> svec;
    sort(svec.begin(), svec.end(), greater<string>());

    vector<string *> nameTable;
    //sort(nameTable.begin(), nameTable.end(),
    //    [](string *a, string *b) {return a < b;}); nameTable中的指针彼此之间没有关系，<将产生未定义行为

    sort(nameTable.begin(), nameTable.end(), less<string *>());

    vector<int> ivec;
    size_t count = std::count_if(ivec.begin(), ivec.end(), bind(greater<int>(), _1, 1024));

    auto word = find_if (svec.cbegin(), svec.cend(), bind(not_equal_to<string>(), _1, "pooch"));

    transform(ivec.begin(), ivec.end(), ivec.begin(), bind(multiplies<int>(), _1, 2));

    vector<int> ivec = {2, 4, 6, 8};
    int num;
    cin >> num;
    std::modulus<int> mod;
    auto is_divisible = any_of(ivec.begin(), ivec.end(), [&mod, &num](int i)->bool{ return 0 == mod(num, i);});
    cout << (is_divisible ? "Yes!" : "No!") << endl;

    system("pause");
    return 0;
}