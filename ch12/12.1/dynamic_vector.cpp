/*
*File : ch12/12.1/dynamic_vector.cpp
*Date : 2022-08-05
*Page : 411
*/

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>

using namespace std;

auto get_vec()
{
    return new vector<int>;
}

void print_out(vector<int>* vptr)
{
    for (auto ival : *vptr)
        cout << ival << " ";
    cout << endl;
    delete vptr;
    vptr = nullptr;
}

void read_in()
{
    int ival;
    auto ivec = get_vec();
    while (cin >> ival) {
        ivec -> push_back(ival);
    }
    print_out(ivec);
}

auto smart_get_vec()
{
    shared_ptr<vector<int>> smart_vec = make_shared<vector<int>>();
    return smart_vec;
}

void smart_print_out(shared_ptr<vector<int>> smart_ivec)
{
    for (auto ival : *smart_ivec)
        cout << ival << " ";
    cout << endl;
}

void smart_read_in()
{
    int ival;
    auto ivec = smart_get_vec();
    while (cin >> ival) {
        ivec -> push_back(ival);
    }
    smart_print_out(ivec);
}

int main()
{
    read_in();
    smart_read_in();
    system("pause");
    return 0;
} 