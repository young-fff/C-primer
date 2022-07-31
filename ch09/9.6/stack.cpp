/*
*File : ch09/9.6/stack.cpp
*Date : 2022-07-29
*Page : 330
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>

using namespace std;

int main()
{
    stack<int> intStack;
    for (size_t ix = 0; ix != 10; ++ix) 
        intStack.push(ix);
    while (!intStack.empty()) {
        int value = intStack.top();
        intStack.pop();
        cout << value << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}