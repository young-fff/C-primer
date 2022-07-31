/*
*File : ch09/9.6/computer.cpp
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
    string expression{"This is (abcde)."};
    bool bSeen = false;
    stack<char> stk;
    for (const auto &s : expression) {
        if (s == '(') {
            bSeen = true;
            continue;
        } else if (s == ')') 
            bSeen = false;
        if (bSeen) stk.push(s);
    }

    string repstr;
    while (!stk.empty()) {
        repstr += stk.top();
        stk.pop();
    }

    expression.replace(expression.find("(") + 1, repstr.size(), repstr);

    cout << expression << endl;

    system("pause");
    return 0;
}