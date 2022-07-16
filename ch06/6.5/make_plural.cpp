/*
*File : ch06/6.5/default_arg.cpp
*Date : 2022-07-16
*Page : 211
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}
int main()
{
    cout << make_plural(1, "success", "") << " " << make_plural(2, "success", "") << endl;
    cout << make_plural(1, "failure") << " " << make_plural(2, "failure") << endl;
    system("pause");
    return 0;
}